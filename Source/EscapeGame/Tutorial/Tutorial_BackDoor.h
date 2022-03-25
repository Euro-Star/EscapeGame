// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/Interactive/DoorBase.h"
#include "Tutorial_BackDoor.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ATutorial_BackDoor : public ADoorBase
{
	GENERATED_BODY()
	
public:
	ATutorial_BackDoor();

	virtual void BeginPlay() override;
};
