#include <iostream>
#include "MonsterAction.h"
#include "MasterCardLibrary.h"
#include "CardTemplate.h"

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

	monster.activeTitle = card.title;
	monster.activeText = card.text;
	monster.activeDam = card.damage;
	monster.activeHealth = card.health;
	monster.activeDefense = card.defense;
	monster.activeArmor = card.armor;
	monster.activeHeal = card.heal;
	
	return monster;
}

void MonsterAction()
{
	//temp value for player move
	int incomingDam = attack->damage;

	//temp values for monster stats
	int tempDam(2), tempHealth(20), tempDefense(2), tempArmor(2), tempHeal(1);


}