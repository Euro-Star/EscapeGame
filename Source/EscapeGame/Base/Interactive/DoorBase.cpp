// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"

//DoorBase�� ��� �޾Ƽ� �� �� KeyName�� bLock�� �������̵� �ؼ� ����(����� �ٸ� ���� ������ ��ĥ ��� GameManager_DefineCode�� �ʱ�ȭ) *
ADoorBase::ADoorBase() {
	PrimaryActorTick.bCanEverTick = false;
	DoorAngle1 = 0.0f;
	DoorAngle2 = 90.0f;
	bOpenOut = false;
	bOpenSound = true;

	Close_Sound = CreateDefaultSubobject<USoundBase>(TEXT("Close Sound"));
	Open_Sound = CreateDefaultSubobject<USoundBase>(TEXT("Open Sound"));
	
	AudioComponent->SetupAttachment(Mesh);
}

void ADoorBase::BeginPlay()
{
	Super::BeginPlay();

	ActorRotate = GetActorRotation();
	if (bOpenOut) {
		OpenOutDoor();
	}
}

//�� ������ �κ�
void ADoorBase::Open() {
	if (bLock == false) {
		bOpen = true;
		if (bOpenSound) {
			PlayOpenSound();
			bOpenSound = false;
		}
		InteractiveDeltaTime += FrameTime * InteractiveSpeed;
		SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(DoorAngle1, DoorAngle2, InteractiveDeltaTime), 0.0f);
		SetActorRotation(SetRotate);
		if (InteractiveDeltaTime >= 1.0f) {
			GetWorldTimerManager().ClearTimer(TimerHandle);
		}
		
	}
	else {
		UnLock();
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

//�� ������ �κ�
void ADoorBase::Close() {
	bOpen = false;
	InteractiveDeltaTime -= FrameTime * InteractiveSpeed;
	SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(DoorAngle2, DoorAngle1, 1 - InteractiveDeltaTime), 0.0f);
	SetActorRotation(SetRotate);
	if (InteractiveDeltaTime <= 0.0f) {
		PlayCloseSound();
		bOpenSound = true;
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

//��ȣ�ۿ�� ����Ǵ� �κ�
void ADoorBase::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADoorBase::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADoorBase::Close, FrameTime, true);
	}
}

//������ ������ ��(�ɼ�)
void ADoorBase::OpenOutDoor() {
	DoorAngle1 = 0.0f;
	DoorAngle2 = -90.0f;
}

// ������ �Ҹ� �÷��̽� ȣ��
void ADoorBase::PlayOpenSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Open_Sound);
	AudioComponent->Play();
}


// ������ �Ҹ� �÷��̽� ȣ��
void ADoorBase::PlayCloseSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Close_Sound);
	AudioComponent->Play();
}
