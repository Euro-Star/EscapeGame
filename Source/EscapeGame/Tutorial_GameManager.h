// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tutorial_GameManager.generated.h"

//게임의 핵심 잠금을 전처리기로 처리(비트연산)-튜토리얼 맵
#define TUTORIALBACKDOOR		0x001
#define FUSEBOX					0x002
#define LAPTOP					0x004
#define LADDER					0x008
#define ROOFFUSEBOX				0x010
#define VEHICLEENTRYBARRIER		0x020
//////////////////////////////////////////////

UCLASS()
class ESCAPEGAME_API ATutorial_GameManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATutorial_GameManager();
	uint32 LockedStatus;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	void ChangeUnLockedStatus(const class AInteractiveBase& _InteractiveBase);
	bool CheckLockedStatus(uint32 CheckCode);
};
