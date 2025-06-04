## 플레이어 개요

### 기본적으로 GAS를 통해 스텟들을 관리


```
사용된 시스템 개요
  - GAS : Gameplay Ability System을 사용하여 능력치 , 효과 , 어빌리티를 관릴
  - AttributeSet : 모든 능력치를 정의하는 클래스
  - GameplayEffect : 상태 변화 ( 피해 , 회복 ) 를 적용하는 효과
  - AbilitySystemComponent : 어빌리티와 능력치의 중심 허브 역할
```

```
Attribute 목록
  = Health ( 체력 )
    플레이어의 생명력을 나타냄. 0이 되면 사망 처리.
  - Mana ( 마나 )
    캐릭터마다의 스킬을 사용할 때 소비하는 자원.
  - Armor ( 방어력 )
    적에게서 받는 데미지를 줄여주는 역할
  - Damage ( 공격력 )
    공격시 적에게 입히는 기본 피해
```

```
PlayerUI
  - Attribute값으로 PlayerUI의 체력 , 마나등을 표시
```
![image](https://github.com/user-attachments/assets/88019e9c-b98d-4181-a1db-1bbec33c1fa3)

```
InventoryUI
  - 적을 처치하여 드랍된 아이템이나 상점에서 구매한 아이템을 표시
```
![image](https://github.com/user-attachments/assets/18258016-ea9f-457c-b2fe-5457316ca07b)

```
EquipmentUI
  - 인벤토리에 있는 아이템을 클릭 시 장착 -> 장착한 아이템을 표시
```
![image](https://github.com/user-attachments/assets/1ae0ba33-2f3d-4654-b10f-9156cce9acea)

```
DeathUI
  - 플레이어의 Health ( 체력 )이 0이 될 경우
```
![image](https://github.com/user-attachments/assets/0132ad27-2bd9-4a39-ab8f-4011b11f534d)

