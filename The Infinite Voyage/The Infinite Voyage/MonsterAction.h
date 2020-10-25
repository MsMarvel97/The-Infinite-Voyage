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

private:
	static void MonsterAction(int pDamage, ActiveMonster& jimbo);
};
