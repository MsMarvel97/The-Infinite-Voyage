#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "MonsterCardLibrary.h"



class ActiveMonster
{
public:
	std::string activeTitle, activeText;
	int activeDam = 0, activeStrength = 0, activeHealth = 0, activeDefense = 0, activeArmor = 0, activeHeal = 0, activeSelfDam = 0;
	

};

class EffectStack
{
public:
	int effectDam = 0, effectEnergy = 0;

};

EffectStack MonsterAction(PlayerCard* pCard, MonsterCard* mCard, ActiveMonster& jimbo);
ActiveMonster InitMonster();