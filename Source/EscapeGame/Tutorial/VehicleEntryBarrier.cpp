// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleEntryBarrier.h"

// Sets default values
AVehicleEntryBarrier::AVehicleEntryBarrier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	GameManager = CreateDefaultSubobject<ATutorial_GameManager>(TEXT("GameManager"));
	RootComponent = Mesh;

	BarrierDeltaTime = 0.0f;
	BarrierSpeed = 1.0f;
	//객체 움직임의 프레임 단위(0.03초당 한번{30프레임})
	FrameTime = 0.03f;
	bUIHelper = false;
	bOpen = false;
	UIText = TEXT("전력이 없습니다.");
	GameManager_DefineCode = VEHICLEENTRYBARRIER;
}

// Called when the game starts or when spawned
void AVehicleEntryBarrier::BeginPlay()
{
	Super::BeginPlay();
	
	ActorRotate = GetActorRotation();
}

void AVehicleEntryBarrier::OpenTimer() {
	bUIHelper = true;
	if (bOpen == false) {
		if (GameManager->CheckLockedStatus(ROOFFUSEBOX) == false) {
			UIText = TEXT("열렸습니다.");
		}
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AVehicleEntryBarrier::OpenBarrier, FrameTime, true);
	}
}

void AVehicleEntryBarrier::OpenBarrier() {
	if (GameManager->CheckLockedStatus(ROOFFUSEBOX) == false) {
		BarrierDeltaTime += FrameTime * BarrierSpeed;
		SetRotate = ActorRotate + FRotator(0.0f, 0.0f, FMath::Lerp(0.0f, 90.0f, BarrierDeltaTime));
		SetActorRotation(SetRotate);
		if (BarrierDeltaTime >= 1.0f) {
			GetWorldTimerManager().ClearTimer(TimerHandle);
			bOpen = true;
		}
	}
	else {
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

