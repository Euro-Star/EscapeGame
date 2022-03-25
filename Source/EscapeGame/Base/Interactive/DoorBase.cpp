// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorBase.h"

//DoorBase를 상속 받아서 쓸 때 KeyName과 bLock을 오버라이딩 해서 쓰기(잠금이 다른 곳에 영향이 끼칠 경우 GameManager_DefineCode도 초기화) *
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

//문 열리는 부분
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

//문 닫히는 부분
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

//상호작용시 실행되는 부분
void ADoorBase::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADoorBase::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &ADoorBase::Close, FrameTime, true);
	}
}

//밖으로 열리게 함(옵션)
void ADoorBase::OpenOutDoor() {
	DoorAngle1 = 0.0f;
	DoorAngle2 = -90.0f;
}

// 열리는 소리 플레이시 호출
void ADoorBase::PlayOpenSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Open_Sound);
	AudioComponent->Play();
}


// 닫히는 소리 플레이시 호출
void ADoorBase::PlayCloseSound() {
	AudioComponent->Stop();
	AudioComponent->SetSound(Close_Sound);
	AudioComponent->Play();
}
