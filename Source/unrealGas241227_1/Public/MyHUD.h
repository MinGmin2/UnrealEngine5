// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAS241227_1_API AMyHUD : public AHUD
{
	GENERATED_BODY()

protected:

	// 우리가 에디터에 넣어줄 클래스 원본. 
	UPROPERTY(BlueprintReadWrite , EditAnywhere , Category = "RPG|UI")
	TSubclassOf<class UHUDWidget> UIHUDWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "RPG|UI")
	class UHUDWidget* UIHUDWidget; // 원본 기준으로 생성된 UI

public:
	class UHUDWidget* GetUI();
	void CreateHUD();

	void SpawnPlayerStateSetting(class AunrealGas241227_1Character* Player);
};
