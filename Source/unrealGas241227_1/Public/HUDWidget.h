// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "HUDWidget.generated.h"

/**
 * 
 */
UCLASS()
class UNREALGAS241227_1_API UHUDWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintImplementableEvent , BlueprintCallable)
	void SetPlayer(class AunrealGas241227_1Character* Player);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentHealth(float CurrentHealth , float MaxHealth);

	/*UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMaxHealth(float MaxHealth);*/

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetCurrentExp(float CurrentExp , float MaxExp);

	/*UFUNCTION(BlueprintImplementableEvent, BlueprintCallable)
	void SetMaxExp(float MaxExp);*/
};
