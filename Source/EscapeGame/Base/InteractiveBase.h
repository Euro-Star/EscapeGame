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
		UStaticMeshComponent* Mesh; // 기본 메시
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
		ATutorial_GameManager* Tutorial_GameManager; // 게임매니저(잠금관리)
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "Initialize")
		float InteractiveSpeed; // 움직이는 객체 속도
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionUIText; // 열 때 나올 UI
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionUIText_Off; // 닫을 때 나올 UI
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "UserInterface")
		FString InteractionLockedUI; // 잠겼을 때 나올 UI
	
	// 위치 바꿀 때 사용함
	FVector ActorLocation;
	FRotator ActorRotate;
	FRotator SetRotate;
	FVector SetLocation;

	// 타이머 사용시 사용
	FTimerHandle TimerHandle; 
	FTimerHandle TimerHandleUIHelper;
	float InteractiveDeltaTime;
	float FrameTime;
	float UIDeltaTime;

	// 잠금 해제 아이템의 정보 저장
	FItemStruct UnLockItem;
	
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category = "Visible")
	bool bOpen; // 열려 있는 지 닫혀 있는지 확인

	//초기화 시켜야 할 것
	UPROPERTY(VisibleAnyWhere, BlueprintReadOnly, Category="Visible")
	bool bLock;
	FName KeyName;
	uint32 GameManager_DefineCode;

	//잠금해제 시 사운드 관련
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
