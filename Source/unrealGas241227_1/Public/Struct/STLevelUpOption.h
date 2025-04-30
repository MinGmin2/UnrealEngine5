#pragma once

#include "CoreMinimal.h"
#include "Enum/EUsedSkill.h"
#include "Enum/ELevelUpType.h"
#include "Enum/EAttributeType.h"
#include "STLevelUpOption.generated.h"

USTRUCT(BlueprintType)
struct FSTLevelUpOption : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnyWhere , BlueprintReadWrite)
	ELevelUpType OptionType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EUsedSkill SkillType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	EAttributeType AttributeType;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	float Value = 0.f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	UTexture2D* Icon = nullptr;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FText Description;
};