// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemStruct.h"
#include <assert.h>

FItemStruct::FItemStruct() {
}

// 인벤토리 초기화를 위한 설정 함수
FItemStruct::FItemStruct(int _null) {
	if (_null == NULL) {
		ItemID = "NoID";
		Name = "NoName";
		Thumbnail = nullptr;
	}
	else {
		assert(nullptr);
	}
}

// 복사생성자
FItemStruct::FItemStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail) {
	ItemID = _ItemID;
	Name = _Name;
	Thumbnail = _Thumbnail;
}

// 초기화 함수
void FItemStruct::InitStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail) {
	ItemID = _ItemID;
	Name = _Name;
	Thumbnail = _Thumbnail;
}
