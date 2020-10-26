//defining BossCardLibrary.h
#ifndef __BossCardLibrary_H__
#define __BossCardLibrary_H__
#endif
//including player.h
#include "Player.h"

//defining Boss class
class Boss {
public:
	//initializing health and defense of boss
	int hp = 30;
	int def = 0;
	//initializing challenge rating
	int m_CR = 0;
	//string to hold text for last boss card played
	std::string lastBCard;

	//getters and setters for above variables
	int get_m_CR() { return m_CR; }
	void set_m_CR(int CR) { m_CR = CR; }

	int get_m_def() { return def; }
	void set_m_def(int d) { def = d; }

	int get_m_hp() { return hp; }
	void set_m_hp(int health) { hp = health; }

	std::string get_lastBCard() { return lastBCard; }
	void set_lastBCard(std::string last) { lastBCard = last; }

	// declaring boss basic cards
	BossCard* rendingClaws = new BossCard;
	BossCard* twistedLash = new BossCard;
	BossCard* evolve = new BossCard;

	//declaring boss advanced cards
	BossCard* fueledRage = new BossCard;
	BossCard* mutate = new BossCard;

	//creating vectors to hold the draw pile and discard pile for the boss
	std::vector<BossCard>BossDraw;
	std::vector<BossCard>BossDiscard;
	//creating an instance of boss card named active to be used by functions that handle the active card
	BossCard active;

	//function for boss to receive damage
	static bool ReceiveDamage(int pDmg);
	
	//function for boss to draw a card
	static void DrawBossCard(std::vector<BossCard>& deck);

	//function for boss to play a card
	static void PlayBossCard(BossCard);

	//function for boss to shuffle their deck
	static void BossShuffle(std::vector<BossCard>& deck);

	//function to get an instance of the Boss class
	static Boss& GetInstance()
	{
		static Boss Instance = Boss();
		return Instance;
	}

private:
	//constructor for Boss
	Boss();
};

