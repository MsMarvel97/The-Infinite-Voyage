#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "MonsterCardLibrary.h"



class ActiveMonster
{
public:
	std::string activeTitle, activeText;
	int activeDam = 0, activeStrength = 0, activeHealth = 0, activeDefense = 0, activeArmor = 0, activeHeal = 0, activeSelfDam = 0;
	int activeDam2 = 0, activeHeal2 = 0, activeSelfDam2 = 0, reduceDmg, rollChance = 0;

};

class EffectStack
{
public:
	int effectDam = 0, effectEnergy = 0;

};

EffectStack MonsterAction(int pDamage, MonsterCard* mCard, ActiveMonster& jimbo);
ActiveMonster InitMonster();