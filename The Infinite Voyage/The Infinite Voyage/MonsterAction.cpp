#include <iostream>
#include "MonsterAction.h"
#include <vector>
#include <random>
#include <algorithm>
using namespace::std;

/*
Things that need to happen:
Get the monster card
Set stats from card
Get moves from card
Get Player card
Apply Player effects
Pick move
Apply move effects to Player
*/

ActiveMonster InitMonster()
{
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	
	mLibrary.MonsterShuffle(mLibrary.MonsterDeck);

	MonsterCard card = mLibrary.MonsterDeck[0];

	ActiveMonster monster;

	monster.activeTitle = card.get_title();
	monster.activeText = card.get_text();
	monster.activeHealth = card.get_m_health();

	if (card.get_strength() > 0)
	{
		monster.activeStrength = card.get_strength();
	}
	if (card.m_heal > 0)
	{
		monster.activeHeal = card.m_heal;
	}
	if (card.m_heal2 > 0)
	{
		monster.activeHeal2 = card.m_heal2;
	}
	if (card.m_damage > 0)
	{
		monster.activeDam = card.m_damage;
	}
	if (card.m_damage2 > 0)
	{
		monster.activeDam2 = card.m_damage2;
	}
	if (card.m_selfDmg > 0)
	{
		monster.activeSelfDam = card.m_selfDmg;
	}
	if (card.m_selfDmg2 > 0)
	{
		monster.activeSelfDam2 = card.m_selfDmg2;
	}

	return monster;
}


EffectStack MonsterAction(int pDamage, MonsterCard* mCard, ActiveMonster& jimbo)
{
	EffectStack outgoing;
	int receivedDamage = pDamage;

	srand(time(0));
	int choice = rand() % 6 + 1;

	//apply player damage
	if (jimbo.reduceDmg > 0)
	{
		jimbo.activeHealth -= receivedDamage - 1;
		jimbo.reduceDmg--;
	}
	else
	{
		jimbo.activeHealth -= receivedDamage;
	}
	//end apply player damage

	//check if dead
	if (jimbo.activeHealth <= 0)
	{
		return outgoing;
	}
	//end check if dead

	//actual action
	if (jimbo.rollChance != 0)//check for multiple moves
	{
		if (choice <= jimbo.rollChance) //roll for first move
		{
			outgoing.effectDam = jimbo.activeDam;
			if (outgoing.effectDam > 0)
			{
				outgoing.effectDam + jimbo.activeStrength;
			}

			jimbo.activeHealth -= jimbo.activeSelfDam;
			jimbo.activeHealth += jimbo.activeHeal;
			return outgoing;
		}
		else // roll for second move
		{
			outgoing.effectDam = jimbo.activeDam2;
			if (outgoing.effectDam > 0)
			{
				outgoing.effectDam + jimbo.activeStrength;
			}

			jimbo.activeHealth += jimbo.activeHeal2;
			jimbo.activeHealth -= jimbo.activeSelfDam2;
			return outgoing;
		}
	}
	else//do move
	{
		if (choice <= jimbo.rollChance) //roll for first move
		{
			outgoing.effectDam = jimbo.activeDam;
			if (outgoing.effectDam > 0)
			{
				outgoing.effectDam + jimbo.activeStrength;
			}

			jimbo.activeHealth -= jimbo.activeSelfDam;
			jimbo.activeHealth += jimbo.activeHeal;
			return outgoing;
		}
	}
	//end actual action
}