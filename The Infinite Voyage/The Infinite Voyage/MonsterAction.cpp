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

ActiveMonster InitMonster(MonsterCard card)
{
	ActiveMonster monster;

	monster.activeTitle = card.get_title();
	monster.activeText = card.get_text();
	monster.activeDam = card.get_damage();
	monster.activeHealth = card.get_health();
	monster.activeDefense = card.get_defense();
	monster.activeArmor = card.get_armor();
	monster.activeHeal = card.get_heal();
	
	return monster;
}

void MonsterAction()
{
	//temp value for player move
	int incomingDam = PlayerCardLibrary::attack->get_damage();
	//temp values for monster stats
	int tempDam(2), tempHealth(20), tempDefense(2), tempArmor(2), tempHeal(1);
}