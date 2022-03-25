// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "MyDrawer.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AMyDrawer : public AInteractiveBase
{
	GENERATED_BODY()

public:
	AMyDrawer();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere)
		float FrameTime;
	UPROPERTY(EditAnyWhere)
		float DrawerSpeed;
	float DrawerDeltaTime;

	UPROPERTY(EditAnyWhere)
		float OpenLimitValue;

	virtual void Open() override;
	virtual void Close() override;
	virtual void Interaction() override;
};
