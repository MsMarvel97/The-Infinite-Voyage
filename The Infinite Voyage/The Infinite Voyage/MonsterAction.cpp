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


void EffectStack::MonsterAction(int pdamage, ActiveMonster& jimbo)
{
	MonsterCard active = jimbo.get_card();
	EffectStack:: outgoing;
	int receiveddamage = pdamage;

	srand(time(0));
	int choice = rand() % 6 + 1;

	//apply player damage
	if (active.get_m_aDR() > 0)
	{
		active.set_m_health(active.get_m_health() - (receiveddamage - 1)) ;
		active.set_m_aDR(active.get_m_health() - 1);
	}
	else
	{
		active.set_m_health(active.get_m_health() - receiveddamage) ;
	}
	//end apply player damage

	//check if dead
	if (jimbo.get_card().get_m_health()<= 0)
	{
		return outgoing;
	}
	//end check if dead

	//*if roll is value of first ability

	//	load in activemonster.choice[0]

	//	damage
	//	damage
	//	vars*

	//actual action
	if (jimbo.get_card().get_m_rollChance() != 0)//check for multiple moves
	{
		if (choice <= jimbo.get_card().get_m_rollChance()) //roll for first move
		{
			outgoing.effectdam = active.get_damage();
			if (outgoing.effectdam > 0)
			{
				outgoing.effectdam + active.get_strength();
			}

			active.set_m_health(active.get_m_health() - active.get_m_A1selfDmg());
			active.set_m_health(active.get_m_health() + active.get_heal());
			return outgoing;
		}

		else // roll for second move
		{
			outgoing.effectdam = active.get_m_A2damage();
			if (outgoing.effectdam > 0)
			{
				outgoing.effectdam + active.get_strength();
			}

			active.set_m_health(active.get_m_health() - active.get_m_A2selfDmg());
			active.set_m_health(active.get_m_health() + active.get_m_A2heal());
			return outgoing;
		}
	}
	else//do move
	{
		if (choice <= jimbo.get_card().get_m_rollChance()) //roll for first move
		{
			outgoing.effectdam = active.get_damage();
			if (outgoing.effectdam > 0)
			{
				outgoing.effectdam + jimbo.activestrength;
			}

			jimbo.activehealth -= jimbo.activeselfdam;
			jimbo.activehealth += jimbo.activeheal;
			return outgoing;
		}
	}
	//end actual action
}
//ActiveMonster InitMonster(MonsterCard* card)
//{
//	ActiveMonster monster;
//
//	monster.activeTitle = card->get_title();
//	monster.activeText = card->get_text();
//	monster.activeDam = card->get_damage();
//	monster.activeHealth = card->get_m_health();
//	monster.activeDefense = card->get_defense();
//	monster.activeArmor = card->get_armor();
//	monster.activeHeal = card->get_heal();
//	
//	return monster;
//}
//
//void ActiveMonster::MonsterAction(PlayerCard* pCard, MonsterCard* mCard, ActiveMonster jimbo)
//{
//	int receivedDamage = pCard->get_damage();
//
//	jimbo.activeHealth -= receivedDamage;
//
//	if (jimbo.activeHealth <= 0)
//	{
//		return;
//	}
//	else
//	{
//		//figure out choosing attack later
//		jimbo.activeHealth += jimbo.activeHeal;
//	}
//}