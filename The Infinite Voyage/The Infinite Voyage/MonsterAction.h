#ifndef __MonsterAction_H__
#define __MonsterAction_H__
#endif
#include "MonsterCardLibrary.h"

class ActiveMonster
{
public:
	ActiveMonster(const MonsterCard& card) {
		_card = card;
	}

	ActiveMonster(const MonsterCard* card) {
		_card = *card;
	}
	MonsterCard& get_card() { return _card; }
	void set_card(MonsterCard card) { _card = card; }

private:
	MonsterCard _card;
};

class EffectStack {
public:
	static void LastAttackText(bool lastAttack, ActiveMonster& jimbo);
	static int MonsterAction (ActiveMonster& jimbo);
	static bool ReceiveDamage(int pDamage, ActiveMonster& jimbo);
private:

};
