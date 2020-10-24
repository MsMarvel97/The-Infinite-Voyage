#ifndef __BossCardLibrary_H__
#define __BossCardLibrary_H__
#endif
#include "Player.h"

class Boss {
public:
	int m_CR;
	int get_m_CR() { return m_CR; }
	void set_m_CR(int CR) { m_CR = CR; }


	// boss basic
	BossCard* rendingClaws = new BossCard;
	BossCard* twistedLash = new BossCard;
	BossCard* evolve = new BossCard;

	//boss advanced 
	BossCard* fueledRage = new BossCard;
	BossCard* mutate = new BossCard;

	BossCard BossCards[2];
	static Boss& GetInstance()
	{
		static Boss Instance = Boss();
		return Instance;
	}

private:
	Boss();
};

