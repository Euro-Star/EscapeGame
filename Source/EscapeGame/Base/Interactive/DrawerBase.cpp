// Fill out your copyright notice in the Description page of Project Settings.


#include "DrawerBase.h"

ADrawerBase::ADrawerBase() {
	PrimaryActorTick.bCanEverTick = false;
	//�����̴� �Ÿ�
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

//������ �κ�
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

//������ �κ�
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

//��ȣ�ۿ� �� ���� �Ǵ� �κ�
void ADrawerBase::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrawerBase::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADrawerBase::Close, FrameTime, true);
	}
}

// ������ �Ҹ� �÷��̽� ȣ��
void ADrawerBase::PlayOpenSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Open_Sound);
	AudioComponent->Play();
}


// ������ �Ҹ� �÷��̽� ȣ��
void ADrawerBase::PlayCloseSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Close_Sound);
	AudioComponent->Play();
}

