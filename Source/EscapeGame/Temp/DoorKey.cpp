// Fill out your copyright notice in the Description page of Project Settings.


#include "DoorKey.h"

ADoorKey::ADoorKey() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("KeyMesh"));
	ItemID = "MyDoorKey";
	Thumbnail = CreateDefaultSubobject<UTexture2D>(TEXT("Thumbnail"));
}
