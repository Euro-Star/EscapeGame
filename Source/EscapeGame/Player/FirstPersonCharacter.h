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

	// ī�޶� ���� ����
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Default")
	class UCameraComponent* FirstPersonCamera;
	class UCharacterMovementComponent* CharacterMovement; // ĳ���� �ӵ� �� ����

	// ���� Ʈ���̽� ��� ����
	FHitResult LineTraceResult; // ���� Ʈ���̽��� ��� ����ü ����
	FVector LineTraceStart; // ������
	FVector LineTraceEnd; // ������ ��
	FCollisionQueryParams DefaltParams;
	class AInteractiveBase* InteractiveActor; // ��ȣ�ۿ� ��ü ����
	class AItemBase* Item; // ������ ��ü ����
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	AActor* InteractiveObj; // HitResult ���� Get�� Actor ����

	// �÷��̾� ���� ���� ����(�ٱ�, �ɱ�)
	bool bisRun;
	bool bisSitDown;
	float WalkSpeed; // �÷��̾� �ӵ�

	// �κ��丮
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	TArray<FItemStruct> Inventory;
	FItemStruct EquipmentItem; // ������ ������
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Visible")
	int EquipedValue; // ������ �������� ĭ


	// UI ���� ����
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
