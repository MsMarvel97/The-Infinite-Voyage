#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "PlayerCardLibrary.h"

class ActiveMonster
{
public:
	string activeTitle = "Something is wrong", activeText = "Something is wrong";
	int activeDam = 0 , activeHealth = 0, activeDefense = 0, activeArmor = 0, activeHeal = 0;
};

void MonsterAction(PlayerCard playedCard, MonsterCard playedMonster, ActiveMonster jimbo);

ActiveMonster InitMonster(MonsterCard* card);