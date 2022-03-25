// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawerBase.h"

ADrawerBase::ADrawerBase() {
	PrimaryActorTick.bCanEverTick = false;
	//움직이는 거리
	OpenLimitValue = 100.0f;
	bOpenSound = true;

	Close_Sound = CreateDefaultSubobject<USoundBase>(TEXT("Close Sound"));
	Open_Sound = CreateDefaultSubobject<USoundBase>(TEXT("Open Sound"));

	AudioComponent->SetupAttachment(Mesh);
}

void ADrawerBase::BeginPlay()
{
	Super::BeginPlay();

	ActorLocation = RootComponent->GetComponentLocation();
}

//열리는 부분
void ADrawerBase::Open() {
	if (bLock == false) {
		bOpen = true;
		if (bOpenSound) {
			PlayOpenSound();
			bOpenSound = false;
		}
		InteractiveDeltaTime += FrameTime * InteractiveSpeed;
		SetLocation = ActorLocation + GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(InteractiveDeltaTime, 0.0f, 1.0f));
		SetActorLocation(SetLocation);
		if (InteractiveDeltaTime >= 1.0f) {
			GetWorldTimerManager().ClearTimer(TimerHandle);
		}
	}
	else {
		UnLock();
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

//닫히는 부분
void ADrawerBase::Close() {
	bOpen = false;
	InteractiveDeltaTime -= FrameTime * InteractiveSpeed;
	SetLocation = ActorLocation + GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(InteractiveDeltaTime, 0.0f, 1.0f));
	SetActorLocation(SetLocation);
	if (InteractiveDeltaTime <= 0.0f) {
		PlayCloseSound();
		bOpenSound = true;
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

//상호작용 시 실행 되는 부분
void ADrawerBase::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrawerBase::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrawerBase::Close, FrameTime, true);
	}
}

// 열리는 소리 플레이시 호출
void ADrawerBase::PlayOpenSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Open_Sound);
	AudioComponent->Play();
}


// 닫히는 소리 플레이시 호출
void ADrawerBase::PlayCloseSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Close_Sound);
	AudioComponent->Play();
}

