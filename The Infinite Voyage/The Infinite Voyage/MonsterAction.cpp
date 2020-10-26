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


//function to receive damage for monster and check if it has died
bool EffectStack::ReceiveDamage(int pdamage, ActiveMonster& jimbo) {
	//bool to check if monster is dead
	bool dead = false;
	//setting the get_card function for the monster to simplify further references
	MonsterCard& active = jimbo.get_card();
	//integer to hold damage dealt by player
	int receiveddamage = pdamage;



	//apply player damage\\
	//checking if monster has damage reduction available
	if (active.get_m_aDR() > 0)
	{
		//reducing monster health value by player damage value - monster damage reduction
		active.set_m_health(active.get_m_health() - (receiveddamage - 1));
		//reducing monster's damage reduction by 1
		active.set_m_aDR(active.get_m_health() - 1);
	}

	else
	{
		//reducing monster health value by player damage value
		active.set_m_health(active.get_m_health() - receiveddamage);
	}
	//end apply player damage


	//check if monster has 0 or fewer health
	if (active.get_m_health() <= 0)
	{
		//returning bool to show that monster is dead
		return dead = true;
	}
	
}

//function to handle monster damage
int EffectStack::MonsterAction(ActiveMonster& jimbo)
{
	//setting the get_card function for the monster to simplify further references
	MonsterCard& active = jimbo.get_card();
	//int to store outgoing damage
	int outgoing = 0;
	//randomizing monster ability
	srand(time(0));
	//determining monster ability with a die roll
	int choice = rand() % 6 + 1;

		
		if (jimbo.get_card().get_m_rollChance() != 0)//check for multiple moves
		{
			if (choice <= jimbo.get_card().get_m_rollChance()) //roll for first move
			{
				//setting outgoing damage to damage value of active monster
				outgoing = active.get_damage();

				//checking if monster will do damage
				if (outgoing > 0)
				{
					//increasing outgoing damage by monster strength
					outgoing += active.get_strength();
				}

				//reducing monster health by ability self-damage value
				active.set_m_health(active.get_m_health() - active.get_m_A1selfDmg());
				//increasing monster health by monster heal value
				active.set_m_health(active.get_m_health() + active.get_heal());
				//increasing monster strength by monster strength value
				active.set_strength(active.get_m_A1strength() + active.get_strength());
				//setting text for last attack
				EffectStack::LastAttackText(true, jimbo);
			}

			else // roll for second move
			{
				//setting outgoing damage to damage value of active monster
				outgoing = active.get_m_A2damage();
				//checking if monster will do damage
				if (outgoing > 0)
				{
					//increasing outgoing damage by monster strength
					outgoing += active.get_strength();
				}

				//reducing monster health by monster self-damage value on second ability
				active.set_m_health(active.get_m_health() - active.get_m_A2selfDmg());
				//increasing monster health by monster heal value on second ability
				active.set_m_health(active.get_m_health() + active.get_m_A2heal());
				//increasing monster strength value by monster strength value on second ability
				active.set_strength(active.get_m_A2strength() + active.get_strength());
				EffectStack::LastAttackText(false, jimbo);
			}
		}
		else//using ability one as monster has no second ability
		{
			
			if (choice <= jimbo.get_card().get_m_rollChance()) //roll for first move
			{
				outgoing = active.get_damage();
				if (outgoing > 0)
				{
					outgoing += active.get_strength();
				}

				active.set_m_health(active.get_m_health() - active.get_m_A1selfDmg());
				active.set_m_health(active.get_m_health() + active.get_heal());
			}
			EffectStack::LastAttackText(true, jimbo);
		}
		//returns the damage that will be done to the player
		return outgoing;
}

//setting message for last attack
void EffectStack::LastAttackText(bool lastAttack, ActiveMonster& monster) {
	MonsterCard& active = monster.get_card();
	//if lastAttack is true it will set the first ability text
	if (lastAttack == true) {
		active.set_m_lastAttack(active.get_m_a1Text());
	}
	//if lastAttack is false it will set the second ability text
	else {
		active.set_m_lastAttack(active.get_m_a2Text());
	}
}