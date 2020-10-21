#pragma once
#include "CardTemplate.h"

class ActiveMonster
{
public:
	string activeTitle, activeText;
	int activeDam, activeHealth, activeDefense, activeArmor, activeHeal;
};

ActiveMonster InitMonster(MonsterCard card);