// Fill out your copyright notice in the Description page of Project Settings.


#include "MyDrawer.h"

AMyDrawer::AMyDrawer() {
	PrimaryActorTick.bCanEverTick = false;
	DrawerDeltaTime = 0.0f;
	DrawerSpeed = 1.0f;
	//��ü �������� ������ ����(0.03�ʴ� �ѹ�{30������})
	FrameTime = 0.03f;
	OpenLimitValue = 100.0f;
}

void AMyDrawer::BeginPlay()
{
	Super::BeginPlay();

	ActorLocation = RootComponent->GetComponentLocation();

}

void AMyDrawer::Open() {
	bOpen = true;
	DrawerDeltaTime += FrameTime * DrawerSpeed;
	SetLocation = ActorLocation + GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(DrawerDeltaTime, 0.0f, 1.0f));
	SetActorLocation(SetLocation);
	if (DrawerDeltaTime >= 1.0f) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AMyDrawer::Close() {
	bOpen = false;
	DrawerDeltaTime -= FrameTime * DrawerSpeed;
	SetLocation = ActorLocation + GetActorForwardVector() * (OpenLimitValue * FMath::Clamp(DrawerDeltaTime, 0.0f, 1.0f));
	SetActorLocation(SetLocation);
	if (DrawerDeltaTime <= 0.0f) {
		GetWorldTimerManager().ClearTimer(TimerHandle);
	}
}

void AMyDrawer::Interaction() {
	if (!bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyDrawer::Open, FrameTime, true);
	}
	else if (bOpen) {
		GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyDrawer::Close, FrameTime, true);
	}
}
