// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/MySaveGame.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "Car.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ACar : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	ACar();

	virtual void BeginPlay() override;
	virtual void Interaction() override;
};
