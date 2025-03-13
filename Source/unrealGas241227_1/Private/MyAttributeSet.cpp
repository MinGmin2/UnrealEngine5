// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAttributeSet.h"
#include "Net/UnrealNetwork.h" //�𸮾� ��Ʈ��ũ ���
#include "GameplayEffect.h" //�ɷ�ġ ���޿� ����Ʈ,�±�, �׷��� ���� �����
#include "GameplayEffectExtension.h" //Ȯ���
UMyAttributeSet::UMyAttributeSet()
{
}
void UMyAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet,Health, OldHealth);
}
void UMyAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Mana, OldMana);
}
void UMyAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxMana, OldMaxMana);
}
void UMyAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxHealth, OldMaxHealth);
}
void UMyAttributeSet::OnRep_Exp(const FGameplayAttributeData& OldExp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Exp, OldExp);
}
void UMyAttributeSet::OnRep_MaxExp(const FGameplayAttributeData& OldMaxExp)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MaxExp, OldMaxExp)
}
void UMyAttributeSet::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Damage, OldDamage)
}
void UMyAttributeSet::OnRep_PlayerLevel(const FGameplayAttributeData& OldPlayerLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, PlayerLevel, OldPlayerLevel);
}
void UMyAttributeSet::OnRep_Armor(const FGameplayAttributeData& OldArmor)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, Armor, OldArmor);
}
void UMyAttributeSet::OnRep_AttackSpeed(const FGameplayAttributeData& OldAttackSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, AttackSpeed, OldAttackSpeed);
}
void UMyAttributeSet::OnRep_MoveSpeed(const FGameplayAttributeData& OldMoveSpeed)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UMyAttributeSet, MoveSpeed, OldMoveSpeed);
}
//���Լ��� �־�� multicast ���� ����
void UMyAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Exp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MaxExp, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, PlayerLevel, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Damage, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, Armor, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, AttackSpeed, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UMyAttributeSet, MoveSpeed, COND_None, REPNOTIFY_Always);
}
//���� ������ ȣ�� �Ǵ� �̺�Ʈ Ȯ���ϴ� �κ�
void UMyAttributeSet::PostGameplayEffectExecute(const struct FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	if (Data.EvaluatedData.Attribute == GetHealthAttribute()) //ü���� ����ȰŸ� ��
	{
		//GetHealth() ���� ����� �� ��
		SetHealth(FMath::Clamp(GetHealth(), 0.f, 1000.f));; //0~1000���̷� ü�� ����
		HealthChaneDelegate.Broadcast(GetHealth(), Data.EffectSpec.StackCount);
		//ü�� ����� ��������Ʈ�� �ִ� ��� �Լ��� ü�� ���� ��Ƽĳ��Ʈ
	}

	
}
