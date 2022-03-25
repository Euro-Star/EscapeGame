// Fill out your copyright notice in the Description page of Project Settings.


#include "LadderDown.h"

ALadderDown::ALadderDown() {
	KeyName = "NoneKey";
	TeleportLocation = CreateDefaultSubobject<ATargetPoint>(TEXT("TeleportLocation"));
	InteractionUIText = TEXT("내려가기");
}

void ALadderDown::Interaction() {
	Player->SetActorLocation(TeleportLocation->GetActorLocation());
	Player->SetActorRotation(TeleportLocation->GetActorRotation());
}
