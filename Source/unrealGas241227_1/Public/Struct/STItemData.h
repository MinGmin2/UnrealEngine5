#pragma once

#include "CoreMinimal.h"
#include "Enum/EItemRarity.h"
#include "Enum/EItemType.h"
#include "Enum/EAttributeType.h"
#include "STItemData.generated.h"

USTRUCT(BlueprintType)
struct FSTItemData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere , BlueprintReadWrite)
	FName ItemID;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FText ItemName;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UStaticMesh* ItemMesh;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float DropRate;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UTexture2D* ItemTexture;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EItemRarity ItemRarity;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EAttributeType ItemAttributeType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EItemType ItemType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	int32 RequiredLevel;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float ItemAttributeValue;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float Price;
};