// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemStruct.h"
#include <assert.h>

FItemStruct::FItemStruct() {
}

// �κ��丮 �ʱ�ȭ�� ���� ���� �Լ�
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

// ���������
FItemStruct::FItemStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail) {
	ItemID = _ItemID;
	Name = _Name;
	Thumbnail = _Thumbnail;
}

// �ʱ�ȭ �Լ�
void FItemStruct::InitStruct(FName _ItemID, FName _Name, UTexture* _Thumbnail) {
	ItemID = _ItemID;
	Name = _Name;
	Thumbnail = _Thumbnail;
}
