// Fill out your copyright notice in the Description page of Project Settings.


#include "FuseBox.h"

AFuseBox::AFuseBox() {
	KeyName = "Fuse";
	InteractionUIText = TEXT("넣기");
	InteractionLockedUI = TEXT("필요한 아이템이 없습니다.");
	GameManager_DefineCode = FUSEBOX;

	ChangeMesh = CreateDefaultSubobject<UStaticMesh>(TEXT("ChangeMesh"));
}

void AFuseBox::BeginPlay() {
	Super::BeginPlay();

	bLock = true;
}

void AFuseBox::Interaction() {
	if (bLock) {
		UnLock();
		if (bLock == false) {
			InteractionUIText = "";
			Mesh->SetStaticMesh(ChangeMesh);
			Mesh->SetMaterial(0, ChangeMesh->GetMaterial(0));
		}
	}
}