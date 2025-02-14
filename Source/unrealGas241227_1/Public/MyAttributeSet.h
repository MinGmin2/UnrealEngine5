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

//��������Ʈ �Ķ���� �ΰ�¥��, �Ӽ� ����ɶ� �Ӽ� ��(float),StackCount(������) �̰� �ΰ� �ش�.
DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FAttributeChangeDelegate, float, Attr, int32, StackCount);
//DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnExpChangeDelegate);
UCLASS()
class UNREALGAS241227_1_API UMyAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UMyAttributeSet();
	
	// -------- ü��(Health) --------
	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	//Health ���� ����ɶ� ReplicatedUsing�Ӽ��� �־��� �Լ� ����
	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Health); //ü�°��� �Լ� �ٸ������

	//���� ü�� ����� ȣ���� �Լ� ��������Ʈ
	FAttributeChangeDelegate HealthChaneDelegate;

	// -------- Maxü��(MaxHealth) --------
	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxHealth);

	// -------- ����ġ(Exp) --------
	UFUNCTION()
	virtual void OnRep_Exp(const FGameplayAttributeData& OldExp);

	UPROPERTY(BlueprintReadOnly , Category = "Attributes" , ReplicatedUsing = OnRep_Exp)
	FGameplayAttributeData Exp;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Exp);

	// -------- Max����ġ(MaxExp) --------
	UFUNCTION()
	virtual void OnRep_MaxExp(const FGameplayAttributeData& OldMaxExp);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_MaxExp)
	FGameplayAttributeData MaxExp;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, MaxExp);

	//FOnExpChangeDelegate ExpChangeDelegate;

	// -------- ����(Level) --------
	UFUNCTION()
	virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	UPROPERTY(BlueprintReadOnly , Category = "Attributes" , ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, Damage);

	// -------- ������(Damage) --------
	UFUNCTION()
	virtual void OnRep_PlayerLevel(const FGameplayAttributeData& OldPlayerLevel);

	UPROPERTY(BlueprintReadOnly, Category = "Attributes", ReplicatedUsing = OnRep_PlayerLevel)
	FGameplayAttributeData PlayerLevel;
	ATTRIBUTE_ACCESSORS(UMyAttributeSet, PlayerLevel);

	//��������Ʈ�� ��Ʈ, �̰� �־�� �� ����� ȣ�� ����
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
	void PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data) override;



};
