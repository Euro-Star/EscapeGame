// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "Engine/TargetPoint.h"
#include "Ladder.generated.h"

/**
  옥상으로 가는 사다리
 */
UCLASS()
class ESCAPEGAME_API ALadder : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	ALadder();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	ATargetPoint* TeleportLocation;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FString Password;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FString Password_Enter;

	virtual void Interaction() override;
	virtual void BeginPlay() override;

	UFUNCTION(BlueprintNativeEvent)
		void CallVisibleUI();
	virtual void CallVisibleUI_Implementation() {

	}

	UFUNCTION(BlueprintCallable)
		void CheckPassword();
};
