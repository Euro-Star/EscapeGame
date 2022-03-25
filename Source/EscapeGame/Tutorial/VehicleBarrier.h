// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "VehicleBarrier.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AVehicleBarrier : public AInteractiveBase
{
	GENERATED_BODY()
public:
	AVehicleBarrier();

	UPROPERTY(EditAnyWhere)
		float BarrierSpeed;
	float BarrierDeltaTime;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		bool bUIHelper;

	virtual void BeginPlay() override;
	void OpenBarrier();
	UFUNCTION(BlueprintCallable)
		void OpenTimer();
};
