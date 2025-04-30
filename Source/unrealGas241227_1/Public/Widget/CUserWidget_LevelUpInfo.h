// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Struct/STLevelUpOption.h"
#include "Enum/EItemRarity.h"
#include "CUserWidget_LevelUpInfo.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAS241227_1_API UCUserWidget_LevelUpInfo : public UUserWidget
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintImplementableEvent)
	void InitLevelUpOption(const TArray<FSTLevelUpOption>& Option);
};
