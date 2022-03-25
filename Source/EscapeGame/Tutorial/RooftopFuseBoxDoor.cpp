// Fill out your copyright notice in the Description page of Project Settings.


#include "RooftopFuseBoxDoor.h"

ARooftopFuseBoxDoor::ARooftopFuseBoxDoor() {
	KeyName = "RooftopFuseboxKey";
}

void ARooftopFuseBoxDoor::BeginPlay() {
	Super::BeginPlay();

	bLock = true;
}