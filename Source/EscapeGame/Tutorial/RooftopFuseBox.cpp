// Fill out your copyright notice in the Description page of Project Settings.


#include "RooftopFuseBox.h"

ARooftopFuseBox::ARooftopFuseBox() {
	ChangeMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("ChangeMesh"));
	Fuse = CreateDefaultSubobject<ARooftopFuse>(TEXT("Fuse"));

	InteractionUIText = TEXT("고치기");
	GameManager_DefineCode = ROOFFUSEBOX;
}

void ARooftopFuseBox::Interaction() {
	Tutorial_GameManager->ChangeUnLockedStatus(*this);
	Mesh->SetStaticMesh(ChangeMesh);
	PlayUnLockedSound();
	Fuse->FixFuse();
}