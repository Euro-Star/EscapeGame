// Fill out your copyright notice in the Description page of Project Settings.


#include "RooftopFuse.h"

// Sets default values
ARooftopFuse::ARooftopFuse()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void ARooftopFuse::BeginPlay()
{
	Super::BeginPlay();
	
}

void ARooftopFuse::FixFuse() {
	SetActorRotation(GetActorRotation() + FRotator(-8.0f, 0.0f, -8.0f));
}
