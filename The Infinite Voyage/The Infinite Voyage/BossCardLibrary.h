#ifndef __BossCardLibrary_H__
#define __BossCardLibrary_H__
#endif
#include "CardTemplate.h"
#include "MasterCardLibrary.h"

class Boss {
public:
	int m_CR = 0;
	int get_m_CR() { return m_CR; }
	void set_m_CR(int CR) { m_CR = CR; }

//boss advanced
BossCard* FueledRage = new BossCard;
BossCard* Mutate = new BossCard;

	// boss basic
	BossCard* RendingClaws;
	BossCard* TwistedLash;
	BossCard* Evolve;

	//boss advanced 
	BossCard* FueledRage;
	BossCard* Mutate;

	BossCard BossCards[2];
	static Boss& GetInstance()
	{
		static Boss Instance = Boss();
		return Instance;
	}

private:
	Boss();
};

