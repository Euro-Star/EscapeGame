// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "Kismet/GameplayStatics.h"
#include "DoorBase.generated.h"

/**
 * 
 */

UCLASS()
class ESCAPEGAME_API ADoorBase : public AInteractiveBase
{
	GENERATED_BODY()

public:
	ADoorBase();

	float DoorAngle1; // ���� ����
	float DoorAngle2; // ������ ����
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="Option")
	bool bOpenOut; // ������ ������ ��

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	USoundBase* Open_Sound;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	USoundBase* Close_Sound;

	bool bOpenSound;

	virtual void BeginPlay() override;

	virtual void Open() override;
	virtual void Close() override;
	virtual void Interaction() override;
	void PlayOpenSound();
	void PlayCloseSound();

	void OpenOutDoor();
};
