// Fill out your copyright notice in the Description page of Project Settings.


#include "FuseBoxDoor.h"

AFuseBoxDoor::AFuseBoxDoor() {
	RightDoor = CreateDefaultSubobject<ADoorBase>(TEXT("RightDoor"));
	LeftDoor = CreateDefaultSubobject<ADoorBase>(TEXT("LeftDoor"));

	DefaultMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("DefaultMesh"));
	ChangeMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("ChangeMesh"));
}

void AFuseBoxDoor::Interaction() {
	RightDoor->Interaction();
	LeftDoor->Interaction();
	if (bOpen) {
		bOpen = false;
		Mesh->SetStaticMesh(DefaultMesh);
	}
	else {
		bOpen = true;
		Mesh->SetStaticMesh(ChangeMesh);
	}
}