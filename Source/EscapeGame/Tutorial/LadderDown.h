// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "Engine/TargetPoint.h"
#include "LadderDown.generated.h"

/**
  ¿Á»ó¿¡¼­ ³»·Á°¡´Â °´Ã¼
 */
UCLASS()
class ESCAPEGAME_API ALadderDown : public AInteractiveBase
{
	GENERATED_BODY()

public:
	ALadderDown();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		ATargetPoint* TeleportLocation;

	virtual void Interaction() override;
};
