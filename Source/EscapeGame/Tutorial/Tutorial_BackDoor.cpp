// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeGame/Tutorial/Tutorial_BackDoor.h"

ATutorial_BackDoor::ATutorial_BackDoor() {
	KeyName = "CrowBar";
	GameManager_DefineCode = TUTORIALBACKDOOR;
}
void ATutorial_BackDoor::BeginPlay() {
	Super::BeginPlay();

	bLock = true;
}