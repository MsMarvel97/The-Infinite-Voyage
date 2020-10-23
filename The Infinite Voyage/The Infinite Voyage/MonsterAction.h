#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "MonsterCardLibrary.h"

class ActiveMonster
{
public:
	std::string activeTitle, activeText;
	int activeDam, activeHealth, activeDefense, activeArmor, activeHeal;
	static void MonsterAction(PlayerCard* pCard, MonsterCard* mCard, ActiveMonster jimbo);
};


ActiveMonster InitMonster(MonsterCard card);