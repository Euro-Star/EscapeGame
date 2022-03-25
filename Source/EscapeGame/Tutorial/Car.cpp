// Fill out your copyright notice in the Description page of Project Settings.


#include "Car.h"

ACar::ACar() {
	KeyName = "NoneKey";
	InteractionUIText = TEXT("출발하기");
	InteractionLockedUI = TEXT("막혀 있습니다.");
}

void ACar::BeginPlay() {
	Super::BeginPlay();

	bLock = true;
}

void ACar::Interaction() {
	if (bLock == false) {
		PlayUnLockedSound();
		UMySaveGame* SaveGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
		SaveGameInstance->bStageClear_Tutorial = true;
		SaveGameInstance->SaveGame();

		APlayerCameraManager* CameraMana = UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0);
		CameraMana->StartCameraFade(0.0f, 1.0f, 1.0f, FColor::Black, false, true);

		FTimerHandle WaitHandle;
		float WaitTime = 2.0f;
		GetWorld()->GetTimerManager().SetTimer(WaitHandle, FTimerDelegate::CreateLambda([&]()
			{
				FName LevelName = "Lobby_Map";
				UGameplayStatics::OpenLevel(GetWorld(), LevelName);
			}), WaitTime, false);
	}
	else {
		if (Tutorial_GameManager->CheckLockedStatus(VEHICLEENTRYBARRIER) == false) {
			bLock = false;
		}
		if (bLock == false) {
			Interaction();
		}
		else {
			UnLock();
		}
	}
}