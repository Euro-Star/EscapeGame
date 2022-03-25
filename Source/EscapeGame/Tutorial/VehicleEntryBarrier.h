// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeGame/Tutorial_GameManager.h"
#include "VehicleEntryBarrier.generated.h"

UCLASS()
class ESCAPEGAME_API AVehicleEntryBarrier : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVehicleEntryBarrier();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UStaticMeshComponent* Mesh;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		ATutorial_GameManager* GameManager;

	FTimerHandle TimerHandle;
	FRotator SetRotate;
	FRotator ActorRotate;
	float FrameTime;
	UPROPERTY(EditAnyWhere)
		float BarrierSpeed;
	float BarrierDeltaTime;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	bool bUIHelper;
	bool bOpen;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly)
		FString UIText;
	uint32 GameManager_DefineCode;

	void OpenBarrier();
	UFUNCTION(BlueprintCallable)
	void OpenTimer();
};
