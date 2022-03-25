// Fill out your copyright notice in the Description page of Project Settings.


#include "VehicleBarrier.h"

AVehicleBarrier::AVehicleBarrier()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	BarrierDeltaTime = 0.0f;
	BarrierSpeed = 1.0f;
	//객체 움직임의 프레임 단위(0.03초당 한번{30프레임})
	FrameTime = 0.03f;
	bUIHelper = false;
	bOpen = false;
	InteractionLockedUI = TEXT("전력이 없습니다.");
	InteractionUIText = TEXT("");
	InteractionUIText_Off = TEXT("");
	GameManager_DefineCode = VEHICLEENTRYBARRIER;
}

void AVehicleBarrier::BeginPlay()
{
	Super::BeginPlay();

	ActorRotate = GetActorRotation();
}

void AVehicleBarrier::OpenTimer() {
	bUIHelper = true;
	if (bOpen == false) {
		if (Tutorial_GameManager->CheckLockedStatus(ROOFFUSEBOX) == false) {
			Tutorial_GameManager->ChangeUnLockedStatus(*this);
			InteractionLockedUI = TEXT("열렸습니다.");
		}
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AVehicleBarrier::OpenBarrier, FrameTime, true);
	}
}

void AVehicleBarrier::OpenBarrier() {
	if (Tutorial_GameManager->CheckLockedStatus(ROOFFUSEBOX) == false) {
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
