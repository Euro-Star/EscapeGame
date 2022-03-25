// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeGame/Struct/ItemStruct.h"
#include "ItemBase.generated.h"

UCLASS(abstract)
class ESCAPEGAME_API AItemBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItemBase();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="Initialize")
		UStaticMeshComponent* Mesh; // 사용할 메시
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		FName ItemID; // 아이템 키 값
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		FName Name; // 아이템 이름
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UTexture* Thumbnail; // 인벤토리 썸네일

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Pickup();
	virtual FItemStruct GetItemInfomation();
};
