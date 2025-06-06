// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"

#include "MyAbilitySystemComponent.h"//어빌리티 시스템
#include "MyAttributeSet.h" //어트뷰트
#include "Enum/EUsedSkill.h"
#include "Struct/STLevelUpOption.h"
#include "Widget/CUserWidget_LevelUpInfo.h"
#include "Struct/STItemData.h"
#include "Engine/DataTable.h"
#include "unrealGas241227_1Character.generated.h"


class UMyAbilitySystemComponent; //클래스 전방선언
class UMyAttributeSet;

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

UCLASS(config=Game)
class AunrealGas241227_1Character : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputMappingContext* DefaultMappingContext;

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* LMBAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RMBAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* QAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	UInputAction* RAction;

public:
	AunrealGas241227_1Character();
	

public: //내꺼 추가
	//어빌리티 시스템 컴포넌트 추가
	

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GASGamePlayAbility")
	class UMyAbilitySystemComponent* AbilitySystemComponent;
	//Get함수
	virtual class UMyAbilitySystemComponent* GetAbilitySystemComponent() const;

	//캐릭터 관련 정보(HP,MP,Damage등 보관)
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GASGamePlayAbility")
	const class UMyAttributeSet* AttributeSetVar;

	//EditDefaultsOnly 에디터에서 초기에 캐릭터의 스킬을 추가
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "GASGamePlayAbility")
	TArray<TSubclassOf<class UGameplayAbility>> InitialAbilities;

	// 스킬 관련 게임 어빌리티, 초기 능력치 세팅
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASGamePlayAbility")
	TSubclassOf<class UGameplayEffect> DefaultAttributes;

	// 기본 체력회복이나 마력 회복 같은거
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "GASGamePlayAbility")
	TArray<TSubclassOf<class UGameplayEffect>> StartUpEffects;

	//플레이어가 해당 캐릭터 조종권한 얻었을때 컨트롤러
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override; //캐릭터 상태가 변경됐을때 호출됨

	UFUNCTION(BlueprintCallable)
	void InitializeAbilitySystem();

public: //스킬 관련 함수

	// 기본 능력치 초기화
	void InitializeAttribute();
	void AddStartUpEffects(); 

	//스킬 어빌리티 하나 초기화
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilitySkill")
	void InitalizeAbility(
		TSubclassOf<class UGameplayAbility> AbilityToGet,
		int32 AbilityLevel);

	//스킬 어빌리티 여러개 한번에 초기화
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilitySkill")
	void InitalizeAbilityMulti(
		TArray<TSubclassOf<class UGameplayAbility>> AbilityToAcquire,
		int32 AbilityLevel);

public: //어빌리티 태그 시스템 관련,

	//FGameplayTagContainer는 태그 여러개 담을수있음.
	//태그 삭제
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilityTag")
	void RemoveAbilityWithTags(FGameplayTagContainer TagContainer);

	//태그 취소
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilityTag")
	void CancelAbilityWithTags(FGameplayTagContainer WithTag,
							   FGameplayTagContainer WithoutTag);

	//태그 하나 추가
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilityTag")
	void AddLooseGamePlayTag(FGameplayTag TagToAdd);

	//태그 하나만 삭제
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilityTag")
	void RemoveLooseGamePlayTag(FGameplayTag TagToRemove);

	//태그 레벨 변경 레벨은 LOL로 치면 스킬레벨,QWER
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbilityTag")
	void ChangeAbilityLevelWithTags(FGameplayTagContainer TagContainer,int32 Level);

public: //캐릭터 속성 관련 기능 추가

	UFUNCTION() //체력 변경될때 불러지는 함수
	void OnHealthChangeNative(float Health, int32 StackCount);

	//BlueprintImplementableEvent 블루프린트에서 이벤트 발생
	// 얘는 c++에서 안만들고 위에 Native가 c++ 구현임
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGamePlayAbility")
	void OnHealthChange(float Health, int32 StackCount);

	//현재 체력을 바로 가져오는거, pure는 구현 없음
	UFUNCTION(BlueprintPure, Category = "GASGamePlayAbility")
	void HealthValues(float& Health, float& MaxHealth);

	//그냥 부름
	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetMaxHealth() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetMana() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetMaxMana() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetExp() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetMaxExp() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetDamage() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetArmor() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetAttackSpeed() const;

	UFUNCTION(BlueprintCallable, Category = "GASGamePlayAbility")
	float GetMoveSpeed() const;

	void CheckLevelUp();
public:
	// 코드에서 부를 함수 ( Die )
	void Die();

	// 죽었을때 부를 함수 블루프린트에서 확인 가능
	UFUNCTION(BlueprintImplementableEvent, Category = "GASGamePlayAbilityAttribute")
	void FinishDying();


protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	// Implement Skill
	void LMBSkill();

	void RMBSkill();
	void RMBSkillTag();

	void QSkill();

	void RSkill();

	UFUNCTION(BlueprintImplementableEvent)
	void OnSkillUsed();

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skills")
	TSubclassOf<UGameplayAbility> LMBSkillClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skills")
	TSubclassOf<UGameplayAbility> RMBSkillClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skills")
	TSubclassOf<UGameplayAbility> QSkillClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Skills")
	TSubclassOf<UGameplayAbility> RSkillClass;

	UPROPERTY(BlueprintReadWrite)
	TArray<EUsedSkill> UnlockSkill;

	// 이제 스킬쿨도 돌리니까 이제 레벨업시에 Unlock Skill에 Contain될 경우에만 되게끔 해야됨.
	// -> 이걸 하려면 UI쪽 LevelUp쪽을 건드려야함 ;; 

	// PlayerLevel
	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Level")
	int32 CurrentLevel = 1;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Level")
	float CurrentExp = 0.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadOnly, Category = "Level")
	float ExpToNextLevel = 100.0f;

	UFUNCTION(BlueprintCallable, Category = "Level")
	void AddExp(float Amount);

	UFUNCTION(BlueprintCallable, Category = "Level")
	void LevelUp();

	UPROPERTY(EditDefaultsOnly, Category = "GAS");
	TSubclassOf<UGameplayEffect> GE_LevelUpEffect;

	// Apply LevelUp Choice Stat of Skill
	UFUNCTION(BlueprintCallable)
	void ApplyLevelUp(const FSTLevelUpOption& Option);

	void ApplyAttributeEffect(EAttributeType Type, float Value);

	UPROPERTY(EditDefaultsOnly, Category = "LevelUp|Effect")
	TSubclassOf<class UGameplayEffect> GE_Damage;

	UPROPERTY(EditDefaultsOnly, Category = "LevelUp|Effect")
	TSubclassOf<class UGameplayEffect> GE_Health;

	UPROPERTY(EditDefaultsOnly, Category = "LevelUp|Effect")
	TSubclassOf<class UGameplayEffect> GE_Armor;

	UPROPERTY(EditDefaultsOnly, Category = "LevelUp|Effect")
	TSubclassOf<class UGameplayEffect> GE_AttackSpeed;

	UPROPERTY(EditDefaultsOnly, Category = "LevelUp|Effect")
	TSubclassOf<class UGameplayEffect> GE_MoveSpeed;

	// LevelUpUI
	UPROPERTY(EditDefaultsOnly , Category = "UI")
	TSubclassOf<UCUserWidget_LevelUpInfo> LevelUpWidgetClass;

	UPROPERTY()
	UCUserWidget_LevelUpInfo* LevelUpWidget;

	UPROPERTY(EditDefaultsOnly , Category = "LevelUp")
	TArray<FSTLevelUpOption> AllLevelUpOption;

	UPROPERTY(VisibleAnyWhere)
	TArray<FSTLevelUpOption> CurrentOption;

	UPROPERTY(EditDefaultsOnly , Category = "LevelUp")
	UDataTable* LevelUpDataOption;

	UFUNCTION(BlueprintCallable, Category = "LevelUp")
	void GenerateRandomLevelUpOption(int32 Count);

	UFUNCTION(BlueprintCallable, Category = "LevelUp")
	void ShowLevelUpUI();

	UFUNCTION(BlueprintCallable)
	void CloseLevelUpUI();
			
	// Obtain Item
	UPROPERTY(EditAnyWhere, BlueprintReadWrite , Category = "Item")
	TArray<FSTItemData> Inventory;

	// EquipItem , Unequip Item
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	FSTItemData ItemData;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
	TMap<EItemType, FActiveGameplayEffectHandle> ActiveEffectHandle;

	UFUNCTION(BlueprintCallable)
	void EquipItem(const FSTItemData& Item);

	UFUNCTION(BlueprintCallable)
	void UnequipItem(EItemType ItemType);

	UFUNCTION(BlueprintCallable)
	void EquipItemValue(EItemType ItemType , float Value);


protected:
	virtual void BeginPlay();

	virtual void NotifyControllerChanged() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

