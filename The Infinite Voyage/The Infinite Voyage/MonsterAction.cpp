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
	monster.activeDam = card.get_damage();
	monster.activeHealth = card.get_m_health();

	if (card.get_defense() > 0)
	{
		monster.activeDefense = card.get_defense();
	}
	if (card.get_strength() > 0)
	{
		monster.activeStrength = card.get_strength();
	}
	if (card.get_armor() > 0)
	{
		monster.activeArmor = card.get_armor();
	}
	if (card.get_heal() > 0)
	{
		monster.activeHeal = card.get_heal();
	}
	if (card.get_m_selfDmg() > 0)
	{
		monster.activeSelfDam = card.get_m_selfDmg();
	}
	return monster;
}


EffectStack MonsterAction(PlayerCard* pCard, MonsterCard* mCard, ActiveMonster& jimbo)
{
	EffectStack outgoing;
	int receivedDamage = pCard->get_damage();

	srand(time(0));
	int choice = rand() % 2;

	jimbo.activeHealth -= receivedDamage;

	if (jimbo.activeHealth <= 0)
	{
		return outgoing;
	}
	jimbo.activeHealth -= jimbo.activeSelfDam;
	if (jimbo.activeHealth <= 0)
	{
		return outgoing;
	}

	jimbo.activeHealth += jimbo.activeHeal;
	jimbo.activeDam += jimbo.activeStrength;
	jimbo.activeDefense += jimbo.activeArmor;

	outgoing.effectDam = jimbo.activeDam;

	return outgoing;
}