// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "EscapeGame/Base/Interactive/DoorBase.h"
#include "FuseBoxDoor.generated.h"

/**
  FuseBox ��
 */
UCLASS()
class ESCAPEGAME_API AFuseBoxDoor : public AInteractiveBase
{
	GENERATED_BODY()

public:
	AFuseBoxDoor();

	// ���ÿ� ������ �ϱ����� Door��ü�� ����
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	ADoorBase* RightDoor;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	ADoorBase* LeftDoor;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	UStaticMesh* DefaultMesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	UStaticMesh* ChangeMesh;


	void virtual Interaction() override;
};
