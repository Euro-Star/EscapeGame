// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/Interactive/DoorBase.h"
#include "RooftopFuseBoxDoor.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ARooftopFuseBoxDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	ARooftopFuseBoxDoor();

	virtual void BeginPlay() override;
};
