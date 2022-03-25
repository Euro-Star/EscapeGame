// Fill out your copyright notice in the Description page of Project Settings.


#include "EscapeGame/Tutorial/CrowBar.h"

ACrowBar::ACrowBar() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CrowBar"));
	ItemID = "CrowBar";
	Name = TEXT("쇠지렛대");
	Thumbnail = CreateDefaultSubobject<UTexture>(TEXT("Thumbnail"));
}