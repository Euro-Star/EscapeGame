// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

// InteractivBase의 자식을 가져옴 ////////////////////
#include "EscapeGame/Tutorial/Tutorial_BackDoor.h"
//#include "EscapeGame/Tutorial/FuseBox.h"
#include "EscapeGame/Tutorial/Laptop.h"
#include "EscapeGame/Tutorial/Ladder.h"
//#include "EscapeGame/Tutorial/RoofFuseBox.h"
//#include "EscapeGame/Tutorial/VehicleEntryBarrier.h"
/////////////////////////////////////////////////////////

#include "InteractionManager.generated.h"

#define TUTORIALBACKDOOR		0x001
#define FUSEBOX					0x002
#define LAPTOP					0x004
#define LADDER					0x008
#define ROOFFUSEBOX				0x010
#define VEHICLEENTRYBARRIER		0x020

UCLASS()
class ESCAPEGAME_API AInteractionManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInteractionManager();
	uint32 LockedStatus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
