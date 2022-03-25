// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EscapeGame/Struct/ItemStruct.h"
#include "FirstPersonCharacter.generated.h"

UCLASS()
class ESCAPEGAME_API AFirstPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AFirstPersonCharacter();

	// 카메라 관련 변수
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Default")
	class UCameraComponent* FirstPersonCamera;
	class UCharacterMovementComponent* CharacterMovement; // 캐릭터 속도 등 제어

	// 라인 트레이스 사용 변수
	FHitResult LineTraceResult; // 라인 트레이스에 닿는 구조체 저장
	FVector LineTraceStart; // 시작점
	FVector LineTraceEnd; // 끝나는 점
	FCollisionQueryParams DefaltParams;
	class AInteractiveBase* InteractiveActor; // 상호작용 객체 저장
	class AItemBase* Item; // 아이템 객체 저장
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	AActor* InteractiveObj; // HitResult 에서 Get한 Actor 저장

	// 플레이어 조작 관련 변수(뛰기, 앉기)
	bool bisRun;
	bool bisSitDown;
	float WalkSpeed; // 플레이어 속도

	// 인벤토리
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	TArray<FItemStruct> Inventory;
	FItemStruct EquipmentItem; // 장착한 아이템
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Visible")
	int EquipedValue; // 장착한 아이템의 칸


	// UI 관련 변수
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="UserInterface")
	bool bLockUIHelper;
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
	bool bLockUIHelper_Debug;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void MoveRight(float AxisValue);
	void MoveForward(float AxisValue);
	void RunStart();
	void RunStop();
	void Interaction();
	void ChangeRightEquipment();
	void ChangeLeftEquipment();
	void SitDown();
};
