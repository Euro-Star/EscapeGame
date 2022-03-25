// Fill out your copyright notice in the Description page of Project Settings.


#include "Laptop.h"

ALaptop::ALaptop() {
	bShowUI = false;
	InteractionUIText = TEXT("켜기");
	InteractionLockedUI = TEXT("전력이 없습니다.");
	KeyName = "None";
	GameManager_DefineCode = LAPTOP;
	Password = "9178";
}

void ALaptop::BeginPlay() {
	Super::BeginPlay();
	bLock = true;
}

void ALaptop::Interaction() {
	if (bLock == false) {
		//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Fail"));
		CallVisibleUI();
	}
	else {
		bLock = Tutorial_GameManager->CheckLockedStatus(FUSEBOX);
		if (bLock == false) {
			Interaction();
		}
		else {
			UnLock();
		}
	}
}