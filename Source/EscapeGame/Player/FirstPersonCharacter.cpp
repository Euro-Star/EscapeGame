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

	//ī�޶� ���� ������
	FirstPersonCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	FirstPersonCamera->SetupAttachment(GetCapsuleComponent());
	FirstPersonCamera->SetRelativeLocation(FVector(0.0f, 0.0f, 40.0f + BaseEyeHeight));
	FirstPersonCamera->bUsePawnControlRotation = true;

	//ĳ���� �⺻ �ӵ�
	CharacterMovement = GetCharacterMovement();
	CharacterMovement->MaxWalkSpeed = 200.0f;

	//�÷��̾ �ڽ��� �޽ø� �� �� ������
	GetMesh()->SetOwnerNoSee(true);

	//�⺻�� �ʱ�ȭ
	InteractiveActor = nullptr;
	bisRun = false;
	bisSitDown = false;
	WalkSpeed = 200.0f;

	// �κ��丮 �ʱ�ȭ
	Inventory.Init(NULL, 4);
	EquipedValue = 0;
	EquipmentItem = Inventory[EquipedValue];

	// UI ���̰� �ϴ� ��
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

	//LineTrace ������, ��������
	LineTraceStart = FirstPersonCamera->GetComponentLocation();
	LineTraceEnd = FirstPersonCamera->GetComponentLocation() + FirstPersonCamera->GetForwardVector() * 120.0f;
	
	//LineTrace ���
	GetWorld()->LineTraceSingleByChannel(LineTraceResult, LineTraceStart, LineTraceEnd, ECC_Visibility, DefaltParams);
	//DrawDebugLine(GetWorld(), LineTraceStart, LineTraceEnd, FColor(0, 255, 0, 0), true, 1.0f , 0 ,2);
	
	//LineTrace ���� ���� ������
	//GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, UKismetSystemLibrary::GetDisplayName(LineTraceResult.GetActor()));
	
	InteractiveObj = LineTraceResult.GetActor();

	//LineTrace ���� ���� �θ���ͷ� ĳ����
	InteractiveActor = Cast<AInteractiveBase>(InteractiveObj);
	Item = Cast<AItemBase>(InteractiveObj);
}

// Called to bind functionality to input
void AFirstPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//X�� Y�� �����̴� Ű ���ε�
	PlayerInputComponent->BindAxis("MoveForward", this, &AFirstPersonCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AFirstPersonCharacter::MoveRight);

	//���콺�� ī�޶� ȸ�� Ű ���ε�
	PlayerInputComponent->BindAxis("Turn", this, &AFirstPersonCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &AFirstPersonCharacter::AddControllerPitchInput);

	//�ٴ� Ű ���ε�
	PlayerInputComponent->BindAction("Run", IE_Pressed, this, &AFirstPersonCharacter::RunStart);
	PlayerInputComponent->BindAction("Run", IE_Released, this, &AFirstPersonCharacter::RunStop);

	//��ȣ�ۿ� Ű ���ε�
	PlayerInputComponent->BindAction("Interaction", IE_Pressed, this, &AFirstPersonCharacter::Interaction);

	//������ �ٲٴ� Ű ���ε�
	PlayerInputComponent->BindAction("ChangeEquipLeft", IE_Pressed, this, &AFirstPersonCharacter::ChangeLeftEquipment);
	PlayerInputComponent->BindAction("ChangeEquipRight", IE_Pressed, this, &AFirstPersonCharacter::ChangeRightEquipment);

	//�ɱ� Ű ���ε�
	PlayerInputComponent->BindAction("SitDown", IE_Pressed, this, &AFirstPersonCharacter::SitDown);
}

//X�� ������
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

//Y�� ������
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

//�ٴ� �Ϳ� ���� �Լ�
void AFirstPersonCharacter::RunStart() {
	bisRun = true;
}
void AFirstPersonCharacter::RunStop() {
	bisRun = false;
}

//��ȣ�ۿ뿡 ���� �Լ�
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

// �κ��丮 ���� ��������
void AFirstPersonCharacter::ChangeLeftEquipment() {
	if (0 < EquipedValue) {
		--EquipedValue;
		EquipmentItem = Inventory[EquipedValue];
	}
}

// �κ��丮 ���� ����������
void AFirstPersonCharacter::ChangeRightEquipment() {
	if (3 > EquipedValue) {
		++EquipedValue;
		EquipmentItem = Inventory[EquipedValue];
	}
}

// �ɱ�
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
