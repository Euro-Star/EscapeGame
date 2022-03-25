// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "DrawerBase.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ADrawerBase : public AInteractiveBase
{
	GENERATED_BODY()

public:
	ADrawerBase();

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="initialize")
	float OpenLimitValue;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "initialize")
	USoundBase* Open_Sound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "initialize")
	USoundBase* Close_Sound;

	bool bOpenSound;


	virtual void Open() override;
	virtual void Close() override;
	virtual void Interaction() override;
	void PlayOpenSound();
	void PlayCloseSound();
};
