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

class ActiveMonster 
{
public:
	int activeDam, activeHealth, activeDefense, activeArmor, activeHeal;


};


void CreateMonster(MonsterCard card)
{
	ActiveMonster Monster;

	Monster.activeDam = card.damage;
	Monster.activeHealth = card.health;
}

void MonsterAction()
{
	//temp value for player move
	int incomingDam = attack->damage;

	//temp values for monster stats
	int tempDam(2), tempHealth(20), tempDefense(2), tempArmor(2), tempHeal(1);


}