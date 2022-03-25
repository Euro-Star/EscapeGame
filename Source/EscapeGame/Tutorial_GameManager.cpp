// Fill out your copyright notice in the Description page of Project Settings.


#include "Tutorial_GameManager.h"
#include "EscapeGame/Base/InteractiveBase.h"

// Sets default values
ATutorial_GameManager::ATutorial_GameManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	LockedStatus = UINT_MAX;
}

// Called when the game starts or when spawned
void ATutorial_GameManager::BeginPlay()
{
	Super::BeginPlay();
	
}

// ����� Ǯ������ �� ȣ��
void ATutorial_GameManager::ChangeUnLockedStatus(const AInteractiveBase& _InteractiveBase) {
	LockedStatus &= ~_InteractiveBase.GameManager_DefineCode;
}

// ����� Ǯ���� �ִ°� Ȯ���ϴ� �Լ�
bool ATutorial_GameManager::CheckLockedStatus(uint32 _CheckCode) {
	if (LockedStatus & _CheckCode) {
		return true;
	}
	else {
		return false;
	}
}

