// Fill out your copyright notice in the Description page of Project Settings.


#include "HidePaper.h"

AHidePaper::AHidePaper() {
	bOnce = true;
	OpenLimitValue = 30.0f;
}

void AHidePaper::BeginPlay() {
	Super::BeginPlay();

	ActorRotate = GetActorRotation();
	ActorLocation = GetActorLocation();

	InteractionUIText = TEXT("옆으로 치우기");
}

void  AHidePaper::Open() {
	InteractiveDeltaTime += FrameTime * InteractiveSpeed;
	if (Divide_LeftRight == EDivide_LeftRight::E_Left) {
		SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(0.0f, -35.0f, InteractiveDeltaTime), 0.0f);
		SetLocation = ActorLocation - GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(InteractiveDeltaTime, 0.0f, 1.0f));
	}
	else if (Divide_LeftRight == EDivide_LeftRight::E_Right) {
		SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(0.0f, 35.0f, InteractiveDeltaTime), 0.0f);
		SetLocation = ActorLocation + GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(InteractiveDeltaTime, 0.0f, 1.0f));
	}
	SetActorLocation(SetLocation);
	SetActorRotation(SetRotate);
	if (InteractiveDeltaTime >= 1.0f) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
		InteractionUIText = TEXT("");
		bOnce = false;
	}
}

void  AHidePaper::Interaction() {
	if (bOnce) {
		PlayUnLockedSound();
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AHidePaper::Open, FrameTime, true);
	}
}