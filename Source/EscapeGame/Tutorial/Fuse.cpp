// Fill out your copyright notice in the Description page of Project Settings.


#include "Fuse.h"

AFuse::AFuse() {
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Fuse"));
	ItemID = "Fuse";
	Name = TEXT("퓨즈");
	Thumbnail = CreateDefaultSubobject<UTexture>(TEXT("Thumbnail"));
}