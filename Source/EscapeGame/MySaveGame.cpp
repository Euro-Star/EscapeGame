// Fill out your copyright notice in the Description page of Project Settings.


#include "MySaveGame.h"

UMySaveGame::UMySaveGame() {
	bStageClear_Tutorial = false;
}

void UMySaveGame::SaveGame() {
	UGameplayStatics::SaveGameToSlot(this, TEXT("SaveGame"), 0);
}

void UMySaveGame::LoadGame() {
	UMySaveGame* LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::CreateSaveGameObject(UMySaveGame::StaticClass()));
	LoadGameInstance = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("SaveGame"), 0));

	///////////세이브로드/////////////

	bStageClear_Tutorial = LoadGameInstance->bStageClear_Tutorial;

	//////////////////////////////////
}