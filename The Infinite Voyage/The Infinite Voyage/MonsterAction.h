#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "PlayerCardLibrary.h"

class ActiveMonster
{
public:
	string activeTitle, activeText;
	int activeDam, activeHealth, activeDefense, activeArmor, activeHeal;
};

void MonsterAction();

ActiveMonster InitMonster(MonsterCard card);