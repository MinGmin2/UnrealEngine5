## UI 개요

#### 인벤토리는 총 3개의 Widget으로 구성되어있으며, 아이템에 마우스를 올릴 경우 ( Hover ) HoverInfo 위젯이 추가로 존재한다.

```
1. Inventory
2. SingleGearSlot
3. Equipment
```
![image](https://github.com/user-attachments/assets/e07048c2-9c36-49ff-892a-aa6c0d488ce9)
![image](https://github.com/user-attachments/assets/f03478c2-d29f-4b35-a317-684d256ea6a5)
![image](https://github.com/user-attachments/assets/ebecdf7f-c6ce-4c94-ad73-a6e1dbcbc6b2)


#### SingleGear를 통해 생성된 Inventory , Equipment
```
SingleGear로 생성된 아이템을 클릭 시 필요레벨이 된다면 장착 , 장착된 SingleGear를 클릭 시 해제된다.
```
![image](https://github.com/user-attachments/assets/23554a62-5c3b-43a0-9e67-677f75f24c0c)
![image](https://github.com/user-attachments/assets/9266546f-1631-4866-831e-641fdca94850)


#### 획득한 아이템의 정보를 나타내는 HoverInfo
```
아이템의 등급 ( Rarity ) , 종류 , 필요레벨 , 아이템에 해당하는 능력치를 나타낸다.
```
+ [아이템 개요](https://github.com/MinGmin2/UnrealEngine5/blob/main/Outline/Item/%EC%95%84%EC%9D%B4%ED%85%9C%20%EA%B0%9C%EC%9A%94.md)

![image](https://github.com/user-attachments/assets/13690762-e292-4ec7-93ce-97bb45b21269)


#### DamageText
```
적에게 가한 데미지를 나타내는 Widget
```
![image](https://github.com/user-attachments/assets/f130c758-ce19-44e2-bc65-cf9ffa0086da)


#### DungeonUI
```
던전의 정보를 나타내는 Widget ( 나오는 몬스터 , 드랍하는 아이템을 보여줌 )
```
![image](https://github.com/user-attachments/assets/ce849437-6ff6-4210-ab91-81c7a9be9357)
