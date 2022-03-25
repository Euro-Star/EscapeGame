// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "Laptop.generated.h"

/**
  
 */
UCLASS()
class ESCAPEGAME_API ALaptop : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	ALaptop();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FString Password;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FString Password_Enter;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
	bool bShowUI;

	virtual void BeginPlay() override;

	virtual void Interaction() override;
	UFUNCTION(BlueprintNativeEvent)
	void CallVisibleUI();
	virtual void CallVisibleUI_Implementation() {

	}
};
