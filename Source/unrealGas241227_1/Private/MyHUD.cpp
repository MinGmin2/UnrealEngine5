// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "HUDWidget.h"
#include "unrealGas241227_1/unrealGas241227_1Character.h"

UHUDWidget* AMyHUD::GetUI()
{
	return nullptr;
}

void AMyHUD::CreateHUD()
{
	if (UIHUDWidget != nullptr) // 이미 생성한적 있으면
		return;

	if (UIHUDWidgetClass == nullptr)
	{
		UE_LOG(LogTemp, Error, TEXT("%s() Missing UIHUDWidgetClass."), *FString(__FUNCTION__));
		return;
	}

	// 원본 클래스 기준으로 위젯 생성 후 AddToViewPort에 추가해줌.
	UIHUDWidget = CreateWidget<UHUDWidget>(GetWorld(), UIHUDWidgetClass);
	UIHUDWidget->AddToViewport();
}

void AMyHUD::SpawnPlayerStateSetting(AunrealGas241227_1Character* Player)
{
	if (Player && UIHUDWidget)
	{
		UIHUDWidget->SetPlayer(Player);
		UIHUDWidget->SetCurrentHealth(Player->GetHealth());
		UIHUDWidget->SetMaxHealth(Player->GetMaxHealth());
	}
}
