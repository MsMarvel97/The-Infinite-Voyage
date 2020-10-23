#include <iostream>
#include "MonsterAction.h"


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

ActiveMonster InitMonster(MonsterCard* card)
{
	ActiveMonster monster;

	monster.activeTitle = card->get_title();
	monster.activeText = card->get_text();
	monster.activeDam = card->get_damage();
	monster.activeHealth = card->get_health();
	monster.activeDefense = card->get_defense();
	monster.activeArmor = card->get_armor();
	monster.activeHeal = card->get_heal();
	
	return monster;
}

void MonsterAction(PlayerCard playedCard, MonsterCard playedMonster, ActiveMonster jimbo)
{
	int receivedDamage = playedCard.get_damage();

	jimbo.activeHealth -= receivedDamage;

	if (jimbo.activeHealth <= 0)
	{
		return;
	}
	else
	{
		//figure out choosing attack later
		jimbo.activeHealth += jimbo.activeHeal;
	}
}