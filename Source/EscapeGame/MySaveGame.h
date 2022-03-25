// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/SaveGame.h"
#include "MySaveGame.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API UMySaveGame : public USaveGame
{
	GENERATED_BODY()

public:
	UMySaveGame();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		bool bStageClear_Tutorial;

	void SaveGame();
	void LoadGame();
}; 
