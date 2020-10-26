//defining MonsterAction.h
#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
//including MonsterCardLibrary.h
#include "MonsterCardLibrary.h"

//class to handle active monster
class ActiveMonster
{
public:
	//constructor for an active monster based on the current monster card
	ActiveMonster(const MonsterCard& card) {
		_card = card;
	}

	//getter and setter for the active monster card
	MonsterCard& get_card() { return _card; }
	void set_card(MonsterCard card) { _card = card; }

private:
	//declaring the active monster card object
	MonsterCard _card;
};

//class to handle the monster's interaction with the player
class EffectStack {
public:
	//function to handle setting the text for the last attack used
	static void LastAttackText(bool lastAttack, ActiveMonster& jimbo);
	
	//function to handle effects of monster action. Also determines and returns damage dealt by monster action to the player.
	static int MonsterAction (ActiveMonster& jimbo);

	//function for receiving damage from the player and returning a boolean to indicate whether monster is dead
	static bool ReceiveDamage(int pDamage, ActiveMonster& jimbo);
};
