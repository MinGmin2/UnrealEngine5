#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EItemRarity : uint8
{
	Common,
	Uncommon,
	Rare,
	Unique,
	Legendary,
	Epic,
	Mythic
};