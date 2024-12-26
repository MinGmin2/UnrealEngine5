// Copyright Epic Games, Inc. All Rights Reserved.

#include "HomeGameMode.h"
#include "HomeCharacter.h"
#include "UObject/ConstructorHelpers.h"

AHomeGameMode::AHomeGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
