// Fill out your copyright notice in the Description page of Project Settings.


#include "Tuto_Lock.h"

// Sets default values
ATuto_Lock::ATuto_Lock()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	LockMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LockMesh"));
	RootComponent = LockMesh;
}

// Called when the game starts or when spawned
void ATuto_Lock::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATuto_Lock::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

