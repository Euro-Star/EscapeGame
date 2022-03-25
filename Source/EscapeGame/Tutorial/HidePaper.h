// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "HidePaper.generated.h"

/**
  Laptop 비밀번호가 적힌 종이를 가리는 객체
 */
UENUM(BlueprintType)
enum class EDivide_LeftRight : uint8 {
	E_Left = 0			UMETA(DisplayName = "Left"),
	E_Right				UMETA(DisplayName = "Right")
};

UCLASS()
class ESCAPEGAME_API AHidePaper : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	AHidePaper();

	bool bOnce;
	UPROPERTY(EditAnyWhere)
	float OpenLimitValue;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EDivide_LeftRight Divide_LeftRight = EDivide_LeftRight::E_Left;

	virtual void BeginPlay() override;

	virtual void Interaction() override;
	virtual void Open() override;
};
