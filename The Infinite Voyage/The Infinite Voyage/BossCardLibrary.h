#ifndef __BossCardLibrary_H__
#define __BossCardLibrary_H__
#endif
#include "Player.h"

class Boss {
public:
	int hp = 30;
	int def = 0;
	int m_CR = 0;
	std::string lastBCard;

	int get_m_CR() { return m_CR; }
	void set_m_CR(int CR) { m_CR = CR; }

	int get_m_def() { return def; }
	void set_m_def(int d) { def = d; }

	int get_m_hp() { return hp; }
	void set_m_hp(int health) { hp = health; }

	std::string get_lastBCard() { return lastBCard; }
	void set_lastBCard(std::string last) { lastBCard = last; }

	// boss basic
	BossCard* rendingClaws = new BossCard;
	BossCard* twistedLash = new BossCard;
	BossCard* evolve = new BossCard;

	//boss advanced 
	BossCard* fueledRage = new BossCard;
	BossCard* mutate = new BossCard;

	std::vector<BossCard>BossDraw;
	std::vector<BossCard>BossDiscard;
	BossCard active;

	static bool ReceiveDamage(int pDmg);
	static void DrawBossCard(std::vector<BossCard>& deck);
	static void PlayBossCard(BossCard);
	static void BossShuffle(std::vector<BossCard>& deck);
	static void LastBossCard(BossCard);

	static Boss& GetInstance()
	{
		static Boss Instance = Boss();
		return Instance;
	}

private:
	Boss();
};

