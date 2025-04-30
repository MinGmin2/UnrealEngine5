// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Struct/STItemData.h"
#include "Widget/CUserWidget_Inventory.h"
#include "CGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAS241227_1_API UCGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game")
    TSubclassOf<ACharacter> SelectedHeroClass;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game")
    int32 TeamIndex;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Game")
    bool bHeroCreated;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    TArray<FSTItemData> Inventory;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    TArray<UUserWidget*> InventorySlot;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    TMap<EItemType, FSTItemData> EquippedItems;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Inventory")
    float Gold;
};
