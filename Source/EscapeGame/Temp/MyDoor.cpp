// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDoor.h"

AMyDoor::AMyDoor() {
	PrimaryActorTick.bCanEverTick = false;

	DoorDeltaTime = 0.0f;
	DoorSpeed = 1.0f;
	//객체 움직임의 프레임 단위(0.03초당 한번{30프레임})
	FrameTime = 0.03f;
	UIDeltaTime = 0.0f;
	KeyName = "MyDoorKey";
}

void AMyDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorRotate = GetActorRotation();
	bLock = true;
}

void AMyDoor::Open() {
	if (bLock == false) {
		bOpen = true;
		DoorDeltaTime += FrameTime * DoorSpeed;
		SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(0.0f, 90.0f, DoorDeltaTime), 0.0f);
		SetActorRotation(SetRotate);
		if (DoorDeltaTime >= 1.0f) {
			GetWorldTimerManager().ClearTimer(TimerHandle);
		}
	}
	else {
		UnLock();
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AMyDoor::Close() {
	bOpen = false;
	DoorDeltaTime -= FrameTime * DoorSpeed;
	SetRotate = ActorRotate + FRotator(0.0f, FMath::Lerp(90.0f, 0.0f, 1 - DoorDeltaTime), 0.0f);
	SetActorRotation(SetRotate);
	if (DoorDeltaTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AMyDoor::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyDoor::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyDoor::Close, FrameTime, true);
	}
}

void AMyDoor::UnLock() {
	if (IsValid(Player)) {
		if (Player->EquipmentItem.ItemID == KeyName) {
			bLock = false;
			Player->EquipmentItem = NULL;
			Player->Inventory[Player->EquipedValue] = NULL;
		}
		else {
			Player->bLockUIHelper = true;
			GetWorldTimerManager().SetTimer(TimerHandleUIHelper, this, &AMyDoor::UIHelper, FrameTime, true);
		}
	}
	else {
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, TEXT("Fail"));
	}
}

void AMyDoor::UIHelper() {
	UIDeltaTime += FrameTime;
	if (UIDeltaTime > 2.0f) {
		Player->bLockUIHelper = false;
		GetWorldTimerManager().ClearTimer(TimerHandleUIHelper);
		UIDeltaTime = 0.0f;
	}
}