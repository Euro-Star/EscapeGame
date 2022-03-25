// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <assert.h>
#include "ItemStruct.generated.h"

USTRUCT(Atomic, BlueprintType)
struct FItemStruct {
	GENERATED_USTRUCT_BODY()

public:
	FItemStruct();
	FItemStruct(int _null);
	FItemStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail);
	void InitStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail);

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FName ItemID;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		UTexture* Thumbnail;

	// NULL값 확인 하는 연산자
	FItemStruct& operator=(int _null) {
		if (_null ==  NULL) {
			ItemID = "NoID";
			Name = "NoName";
			Thumbnail = nullptr;
		}
		else {
			assert(nullptr);
		}
		return *this;
	}

	// 같은 아이템인 확인 하는 연산자
	bool operator==(const FItemStruct& _ref) {
		if (_ref.ItemID == ItemID) {
			return true;
		}
		else {
			return false;
		}
	}
};
