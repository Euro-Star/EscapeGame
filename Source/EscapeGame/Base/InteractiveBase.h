// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EscapeGame/Struct/ItemStruct.h"
#include "EscapeGame/Player/FirstPersonCharacter.h"
#include "Components/AudioComponent.h"
#include "EscapeGame/Tutorial_GameManager.h"
#include "InteractiveBase.generated.h"

UCLASS(abstract)
class ESCAPEGAME_API AInteractiveBase : public AActor
{
	GENERATED_BODY()
	
public:	
	AInteractiveBase();

	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Player")
		AFirstPersonCharacter* Player;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category="Initialize")
		UStaticMeshComponent* Mesh; // �⺻ �޽�
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
		ATutorial_GameManager* Tutorial_GameManager; // ���ӸŴ���(��ݰ���)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
		float InteractiveSpeed; // �����̴� ��ü �ӵ�
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionUIText; // �� �� ���� UI
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionUIText_Off; // ���� �� ���� UI
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionLockedUI; // ����� �� ���� UI
	
	// ��ġ �ٲ� �� �����
	FVector ActorLocation;
	FRotator ActorRotate;
	FRotator SetRotate;
	FVector SetLocation;

	// Ÿ�̸� ���� ���
	FTimerHandle TimerHandle; 
	FTimerHandle TimerHandleUIHelper;
	float InteractiveDeltaTime;
	float FrameTime;
	float UIDeltaTime;

	// ��� ���� �������� ���� ����
	FItemStruct UnLockItem;
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	bool bOpen; // ���� �ִ� �� ���� �ִ��� Ȯ��

	//�ʱ�ȭ ���Ѿ� �� ��
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Visible")
	bool bLock;
	FName KeyName;
	uint32 GameManager_DefineCode;

	//������� �� ���� ����
	UAudioComponent* AudioComponent;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
	USoundBase* UnLockedSound;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	virtual void Open();
	virtual void Close();
	virtual void Interaction();
	virtual void UnLock();
	virtual void UIHelper();
	virtual void PlayUnLockedSound();

};
