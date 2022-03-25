// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractiveBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AInteractiveBase::AInteractiveBase()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Interactive Mesh"));
	RootComponent = Mesh;
	KeyName = "NoID";
	bLock = false;
	bOpen = false;

	FrameTime = 0.03f;
	InteractiveDeltaTime = 0.0f;
	InteractiveSpeed = 1.0f;
	InteractionUIText = TEXT("열기");
	InteractionUIText_Off = TEXT("닫기");
	InteractionLockedUI = TEXT("잠겨 있습니다.");

	GameManager_DefineCode = 0;
	Tutorial_GameManager = CreateDefaultSubobject<ATutorial_GameManager>(TEXT("GameManager"));
	AudioComponent = CreateDefaultSubobject<UAudioComponent>(TEXT("Audio"));
	UnLockedSound = CreateDefaultSubobject<USoundBase>(TEXT("UnLocked Sound"));
}

void AInteractiveBase::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<AFirstPersonCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));
}

// 닫히는 부분
void AInteractiveBase::Close() {
	
}

// 플레이어와 상호작용 되는 부분
void AInteractiveBase::Interaction() {

}

// 열리는 부분
void AInteractiveBase::Open() {

}

// 잠금을 푸는 함수
void AInteractiveBase::UnLock() {
	if (IsValid(Player)) {
		if (Player->EquipmentItem.ItemID == KeyName) {
			bLock = false;
			Player->EquipmentItem = NULL;
			Player->Inventory[Player->EquipedValue] = NULL;
			Tutorial_GameManager->ChangeUnLockedStatus(*this);
			if (IsValid(UnLockedSound)) {
				PlayUnLockedSound();
			}
		}
		else {
			Player->bLockUIHelper = true;
			Player->bLockUIHelper_Debug = true;
			GetWorldTimerManager().SetTimer(TimerHandleUIHelper, this, &AInteractiveBase::UIHelper, FrameTime, true);
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Fail"));
	}
}

// UI띄우는 함수
void AInteractiveBase::UIHelper() {
	UIDeltaTime += FrameTime;
	Player->bLockUIHelper_Debug = false;
	if (UIDeltaTime > 2.0f) {
		Player->bLockUIHelper = false;
		GetWorldTimerManager().ClearTimer(TimerHandleUIHelper);
		UIDeltaTime = 0.0f;
	}
}

void AInteractiveBase::PlayUnLockedSound() {
	AudioComponent->SetSound(UnLockedSound);
	AudioComponent->Play();
}