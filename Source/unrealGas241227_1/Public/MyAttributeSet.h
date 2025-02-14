// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "MyAbilitySystemComponent.h"
#include "MyAttributeSet.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

struct FGameplayEffectModCallbackData;

//델리게이트 파라미터 두개짜리, 속성 변경될때 속성 값(float),StackCount(뭔지모름) 이거 두개 준다.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChangeDelegate, float, Attr, int32, StackCount);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExpChangeDelegate);
UCLASS()
class UNREALGAS241227_1_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UMyAttributeSet();
	
	// -------- 체력(Health) --------
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	//Health 값이 변경될때 ReplicatedUsing속성에 넣어준 함수 실행
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Health); //체력관련 함수 다만들어줌

	//현재 체력 변경시 호출할 함수 델리게이트
	FAttributeChangeDelegate HealthChaneDelegate;

	// -------- Max체력(MaxHealth) --------
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxHealth);

	// -------- 경험치(Exp) --------
	UFUNCTION()
	virtual void OnRep_Exp(const FGameplayAttributeData& OldExp);

	UPROPERTY(BlueprintReadOnly , Category = "Attributes" , ReplicatedUsing = OnRep_Exp)
	FGameplayAttributeData Exp;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Exp);

	// -------- Max경험치(MaxExp) --------
	UFUNCTION()
	virtual void OnRep_MaxExp(const FGameplayAttributeData& OldMaxExp);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxExp)
	FGameplayAttributeData MaxExp;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxExp);

	//FOnExpChangeDelegate ExpChangeDelegate;

	// -------- 레벨(Level) --------
	UFUNCTION()
	virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	UPROPERTY(BlueprintReadOnly , Category = "Attributes" , ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Damage);

	// -------- 데미지(Damage) --------
	UFUNCTION()
	virtual void OnRep_PlayerLevel(const FGameplayAttributeData& OldPlayerLevel);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerLevel)
	FGameplayAttributeData PlayerLevel;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, PlayerLevel);

	//델리게이트랑 세트, 이거 있어야 값 변경시 호출 가능
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;



};
