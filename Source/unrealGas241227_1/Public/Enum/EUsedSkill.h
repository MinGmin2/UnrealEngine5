#pragma once

#include "CoreMinimal.h"

UENUM(BlueprintType)
enum class EUsedSkill : uint8
{
    LMB     UMETA(DisplayName = "LMB Skill"),
    RMB     UMETA(DisplayName = "RMB Skill"),
    Q       UMETA(DisplayName = "Q Skill"),
    R       UMETA(DisplayName = "R Skill")
};