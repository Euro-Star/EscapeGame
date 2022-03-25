// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "FuseBox.generated.h"

/**
  Laptop ������ ���� ��ü
 */
UCLASS()
class ESCAPEGAME_API AFuseBox : public AInteractiveBase
{
	GENERATED_BODY()
	
public:
	AFuseBox();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UStaticMesh* ChangeMesh;

	void virtual BeginPlay() override;
	void virtual Interaction() override;
};
