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
		UStaticMeshComponent* Mesh; // ����� �޽�
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		FName ItemID; // ������ Ű ��
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		FName Name; // ������ �̸�
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UTexture* Thumbnail; // �κ��丮 �����

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Pickup();
	virtual FItemStruct GetItemInfomation();
};
