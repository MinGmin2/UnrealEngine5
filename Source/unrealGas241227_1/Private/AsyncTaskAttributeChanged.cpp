// Fill out your copyright notice in the Description page of Project Settings.


#include "AsyncTaskAttributeChanged.h"

UAsyncTaskAttributeChanged* UAsyncTaskAttributeChanged::ListenForAttributeChange(UAbilitySystemComponent* AbilitySystemComponent, FGameplayAttribute Attribute)
{
	// static함수라 호출 시 UAsyncTaskAttributeChanged 생성 뒤 호출
	UAsyncTaskAttributeChanged* WaitforAttributeChangeTask = NewObject<UAsyncTaskAttributeChanged>();

	// 블루프린트에서 넣은 정보 저장
	WaitforAttributeChangeTask->ASC = AbilitySystemComponent;
	WaitforAttributeChangeTask->AttributeToListenFor = Attribute;

	// 파라미터가 이상하면
	if (!IsValid(AbilitySystemComponent) || !Attribute.IsValid())
	{
		// 생성한 오브젝트 다시 지움
		WaitforAttributeChangeTask->RemoveFromRoot();
		return nullptr;
	}

	AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitforAttributeChangeTask, &UAsyncTaskAttributeChanged::AttributeChanged);

	return WaitforAttributeChangeTask;
}

UAsyncTaskAttributeChanged* UAsyncTaskAttributeChanged::ListenForAttributesChange(UAbilitySystemComponent* AbilitySystemComponent, TArray<FGameplayAttribute> Attributes)
{
	// static함수라 호출 시 UAsyncTaskAttributeChanged 생성 뒤 호출
	UAsyncTaskAttributeChanged* WaitforAttributeChangeTask = NewObject<UAsyncTaskAttributeChanged>();

	// 블루프린트에서 넣은 정보 저장
	WaitforAttributeChangeTask->ASC = AbilitySystemComponent;
	WaitforAttributeChangeTask->AttributesToListenFor = Attributes;

	// 파라미터가 이상하면
	if (!IsValid(AbilitySystemComponent) || Attributes.Num() < 1)
	{
		// 생성한 오브젝트 다시 지움
		WaitforAttributeChangeTask->RemoveFromRoot();
		return nullptr;
	}

	for (FGameplayAttribute Attribute : Attributes)
	{
		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(Attribute).AddUObject(WaitforAttributeChangeTask, &UAsyncTaskAttributeChanged::AttributeChanged);
	}

	return WaitforAttributeChangeTask;
}

void UAsyncTaskAttributeChanged::EndTask()
{
	if (IsValid(ASC))
	{
		// 안에있는 딜리게이트를 확인해서 다 지운다.
		ASC->GetGameplayAttributeValueChangeDelegate(AttributeToListenFor).RemoveAll(this);

		for (FGameplayAttribute Attribute: AttributesToListenFor)
		{
			ASC->GetGameplayAttributeValueChangeDelegate(Attribute).RemoveAll(this);
		}
	}

	SetReadyToDestroy(); // 테스크 삭제
	MarkAsGarbage(); // ??
}

void UAsyncTaskAttributeChanged::AttributeChanged(const FOnAttributeChangeData& Data)
{
	// 변경된거 함수 전송, 속성, 새로운데이터, 이전 데이터
	OnAttributeChanged.Broadcast(Data.Attribute, Data.NewValue, Data.OldValue);
}
