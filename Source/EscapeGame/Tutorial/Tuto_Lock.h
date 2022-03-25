// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tuto_Lock.generated.h"

UCLASS()
class ESCAPEGAME_API ATuto_Lock : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATuto_Lock();

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* LockMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
