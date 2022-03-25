// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "EscapeGame/Tutorial/RooftopFuse.h"
#include "RooftopFuseBox.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API ARooftopFuseBox : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UStaticMesh* ChangeMesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	ARooftopFuse* Fuse;

	ARooftopFuseBox();

	virtual void Interaction() override;

};
