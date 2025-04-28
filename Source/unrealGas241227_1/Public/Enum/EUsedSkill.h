#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUsedSkill : uint8
{
    LMB     UMETA(DisplayName = "Left Mouse Button"),
    RMB     UMETA(DisplayName = "Right Mouse Button"),
    Q       UMETA(DisplayName = "Q Skill"),
    R       UMETA(DisplayName = "R Skill")
};