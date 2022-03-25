// Fill out your copyright notice in the Description page of Project Settings.


#include "Ladder.h"

ALadder::ALadder() {
	KeyName = "NoneKey";
	TeleportLocation = CreateDefaultSubobject<ATargetPoint>(TEXT("TeleportLocation"));
	InteractionUIText = TEXT("올라가기");
	GameManager_DefineCode = LADDER;
	Password = "9759";
	Password_Enter = "0000";
}

void ALadder::BeginPlay() {
	Super::BeginPlay();

	bLock = true;
}

void ALadder::Interaction() {
	if (bLock == false) {
		Player->SetActorLocation(TeleportLocation->GetActorLocation());
		Player->SetActorRotation(TeleportLocation->GetActorRotation());
	}
	else {
		CallVisibleUI();
	}
}

void ALadder::CheckPassword() {
	if (Password == Password_Enter) {
		PlayUnLockedSound();
		bLock = false;
	}
}