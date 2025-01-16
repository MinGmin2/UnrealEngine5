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

	// �츮�� �����Ϳ� �־��� Ŭ���� ����. 
	UPROPERTY(BlueprintReadWrite , EditAnywhere , Category = "RPG|UI")
	TSubclassOf<class UHUDWidget> UIHUDWidgetClass;

	UPROPERTY(BlueprintReadWrite, Category = "RPG|UI")
	class UHUDWidget* UIHUDWidget; // ���� �������� ������ UI

public:
	class UHUDWidget* GetUI();
	void CreateHUD();

	void SpawnPlayerStateSetting(class AunrealGas241227_1Character* Player);
};
