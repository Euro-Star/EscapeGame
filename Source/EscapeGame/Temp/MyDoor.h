// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "MyDoor.generated.h"

/**
 * 
 */
UCLASS()
class ESCAPEGAME_API AMyDoor : public AInteractiveBase
{
	GENERATED_BODY()

public:
	AMyDoor();

	virtual void BeginPlay() override;

	UPROPERTY(EditAnyWhere)
	float FrameTime;
	UPROPERTY(EditAnyWhere)
	float DoorSpeed;
	float DoorDeltaTime;
	float UIDeltaTime;

	virtual void Open() override;
	virtual void Close() override;
	virtual void Interaction() override;
	virtual void UnLock() override;
	virtual void UIHelper() override;
};
