#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EAttributeType : uint8
{
	Damage,
	Health,
	Armor,
	Heal,
	AS,
	MS
};