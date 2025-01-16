// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAS241227_1_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()

	virtual void OnPossess(APawn* aPawn) override;
	virtual void OnRep_PlayerState() override;
	
};
