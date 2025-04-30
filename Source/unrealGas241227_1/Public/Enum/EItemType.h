#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EItemType : uint8
{
	Helmet,
	TorsoArmor,
	LegArmor,
	Gloves,
	Boots,
	Weapon,
	Potion
};