// Fill out your copyright notice in the Description page of Project Settings.


#include "RooftopFuseboxKey.h"

ARooftopFuseboxKey::ARooftopFuseboxKey() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("RooftopFuseboxKey"));
	ItemID = "RooftopFuseboxKey";
	Name = TEXT("차단기 키");
	Thumbnail = CreateDefaultSubobject<UTexture>(TEXT("Thumbnail"));
}