// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemBase.h"
#include "EscapeGame/Struct/ItemStruct.h"

// 상속 시 Mesh, Thumbnail, ItemID 초기화 하기
AItemBase::AItemBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void AItemBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// 아이템 획득 시 아이템 파괴
void AItemBase::Pickup() {
	Destroy();
}

// 아이템 획득 시 정보 전달
FItemStruct AItemBase::GetItemInfomation() {
	FItemStruct ret(this->ItemID, this->Name, this->Thumbnail);
	return ret;
}

