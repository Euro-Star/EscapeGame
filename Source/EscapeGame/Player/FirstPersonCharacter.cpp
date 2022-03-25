// Fill out your copyright notice in the Description page of Project Settings.


#include "FirstPersonCharacter.h"
#include <Engine/Classes/Camera/CameraComponent.h>
#include <Engine/Classes/Components/CapsuleComponent.h>
#include <Engine/Classes/GameFramework/CharacterMovementComponent.h>
#include "DrawDebugHelpers.h"
#include "Kismet/KismetSystemLibrary.h"
#include "EscapeGame/Base/InteractiveBase.h"
#include "EscapeGame/Base/ItemBase.h"
#include "EscapeGame/Struct/ItemStruct.h"

// Sets default values
AFirstPersonCharacter::AFirstPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//카메라에 대한 생성자
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f + BaseEyeHeight));
	FirstPersonCamera->bUsePawnControlRotation = true;

	//캐릭터 기본 속도
	CharacterMovement = GetCharacterMovement();
	CharacterMovement->MaxWalkSpeed = 200.0f;

	//플레이어만 자신의 메시를 볼 수 없게함
	GetMesh()->SetOwnerNoSee(true);

	//기본값 초기화
	InteractiveActor = nullptr;
	bisRun = false;
	bisSitDown = false;
	WalkSpeed = 200.0f;

	// 인벤토리 초기화
	Inventory.Init(NULL, 4);
	EquipedValue = 0;
	EquipmentItem = Inventory[EquipedValue];

	// UI 보이게 하는 값
	bLockUIHelper = false;
	bLockUIHelper_Debug = false;
}

// Called when the game starts or when spawned
void AFirstPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFirstPersonCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//LineTrace 시작점, 끝나는점
	LineTraceStart = FirstPersonCamera->GetComponentLocation();
	LineTraceEnd = FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * 120.0f;
	
	//LineTrace 사용
	GetWorld()->LineTraceSingleByChannel(LineTraceResult, LineTraceStart, LineTraceEnd, ECC_Visibility, DefaltParams);
	//DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor(0, 255, 0, 0), true, 1.0f , 0 ,2);
	
	//LineTrace 맞은 액터 디버깅용
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, UKismetSystemLibrary::GetDisplayName(LineTraceResult.GetActor()));
	
	InteractiveObj = LineTraceResult.GetActor();

	//LineTrace 맞은 액터 부모액터로 캐스팅
	InteractiveActor = Cast<AInteractiveBase>(InteractiveObj);
	Item = Cast<AItemBase>(InteractiveObj);
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//X축 Y축 움직이는 키 바인딩
	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);

	//마우스로 카메라 회전 키 바인딩
	PlayerInputComponent->BindAxis("Turn", this, &AFirstPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::AddControllerPitchInput);

	//뛰는 키 바인딩
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AFirstPersonCharacter::RunStart);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AFirstPersonCharacter::RunStop);

	//상호작용 키 바인딩
	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &AFirstPersonCharacter::Interaction);

	//아이템 바꾸는 키 바인딩
	PlayerInputComponent->BindAction("ChangeEquipLeft", IE_Pressed, this, &AFirstPersonCharacter::ChangeLeftEquipment);
	PlayerInputComponent->BindAction("ChangeEquipRight", IE_Pressed, this, &AFirstPersonCharacter::ChangeRightEquipment);

	//앉기 키 바인딩
	PlayerInputComponent->BindAction("SitDown", IE_Pressed, this, &AFirstPersonCharacter::SitDown);
}

//X축 움직임
void AFirstPersonCharacter::MoveForward(float AxisValue) {
	if (AxisValue != 0.0f)
	{
		if (bisRun) {
			CharacterMovement->MaxWalkSpeed = WalkSpeed * 2;
		}
		else {
			CharacterMovement->MaxWalkSpeed = WalkSpeed;
		}

		AddMovementInput(GetActorForwardVector(), AxisValue);
	}
}

//Y축 움직임
void AFirstPersonCharacter::MoveRight(float AxisValue) {
	if (AxisValue != 0.0f)
	{
		if (bisRun) {
			CharacterMovement->MaxWalkSpeed = WalkSpeed * 2;
		}
		else {
			CharacterMovement->MaxWalkSpeed = WalkSpeed;
		}

		AddMovementInput(GetActorRightVector(), AxisValue);
	}
}

//뛰는 것에 대한 함수
void AFirstPersonCharacter::RunStart() {
	bisRun = true;
}
void AFirstPersonCharacter::RunStop() {
	bisRun = false;
}

//상호작용에 대한 함수
void AFirstPersonCharacter::Interaction() {
	if (InteractiveActor) {
		InteractiveActor->Interaction();
	}
	if (Item) {
		FItemStruct SaveItem = Item->GetItemInfomation();
		for (auto it = Inventory.begin(); it != Inventory.end(); ++it) {
			if (*it == FItemStruct(NULL)) {
				*it = SaveItem;
				Item->Pickup();
				EquipmentItem = Inventory[EquipedValue];
				break;
			}
		}
	}
}

// 인벤토리 장착 왼쪽으로
void AFirstPersonCharacter::ChangeLeftEquipment() {
	if (0 < EquipedValue) {
		--EquipedValue;
		EquipmentItem = Inventory[EquipedValue];
	}
}

// 인벤토리 장착 오른쪽으로
void AFirstPersonCharacter::ChangeRightEquipment() {
	if (3 > EquipedValue) {
		++EquipedValue;
		EquipmentItem = Inventory[EquipedValue];
	}
}

// 앉기
void AFirstPersonCharacter::SitDown() {
	if (bisSitDown == false) {
		bisSitDown = true;
		FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, (40.0f + BaseEyeHeight) / 3));
		WalkSpeed = 100.0f;
		CharacterMovement->MaxWalkSpeed = WalkSpeed;
	}
	else {
		bisSitDown = false;
		FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, (40.0f + BaseEyeHeight)));
		WalkSpeed = 200.0f;
		CharacterMovement->MaxWalkSpeed = WalkSpeed;
	}
}
