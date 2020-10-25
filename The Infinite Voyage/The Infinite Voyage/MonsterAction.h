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

	//std::string activeTitle, activeText;
	//int activeDam, activeHealth, activeDefense, activeArmor, activeHeal;
	////ActiveMonster InitMonster(MonsterCard* card);

	//static ActiveMonster& GetInstance(MonsterCard* card)
	//{
	//	static ActiveMonster Monster = ActiveMonster();
	//	return Monster;
	//}
	MonsterCard& get_card() { return _card; }
	void set_card(MonsterCard card) { _card = card; }

private:
	MonsterCard _card;
	//ActiveMonster(MonsterCard* card);

};

class EffectStack {
public:

private:
	static void MonsterAction(int pDamage, MonsterCard* mCard, ActiveMonster& jimbo);
};
