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
	BossCard* RendingClaws = new BossCard;
	BossCard* TwistedLash = new BossCard;
	BossCard* Evolve = new BossCard;

	//boss advanced 
	BossCard* FueledRage = new BossCard;
	BossCard* Mutate = new BossCard;

	BossCard BossCards[2];
	static Boss& GetInstance()
	{
		static Boss Instance = Boss();
		return Instance;
	}

private:
	Boss();
};

