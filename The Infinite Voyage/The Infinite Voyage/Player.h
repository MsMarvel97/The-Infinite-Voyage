#ifndef __Player_H__
#define __Player_H__
#endif
#include "MonsterAction.h"
#include <vector>
#include <algorithm>
#include <random>

class Player {
public:
	int health = 20, energy = 3, armor = 0, defense = 0, strength = 0;
	bool endRound = false;

	int get_strength() { return strength; }
	void set_strength(int str) { strength = str; }

	int get_armor() { return armor; }
	void set_armor(int arm) { armor = arm; }

	int get_defense() { return defense; }
	void set_defense(int def) { defense = def; }

	int get_health() { return health; }
	void set_health(int hp) { health = hp; }

	int get_energy() { return energy; }
	void set_energy(int en) { energy = en; }

	bool get_endRound() { return endRound; }
	void set_endRound(bool ER) { endRound = ER; }


	static void Shuffle (std::vector<PlayerCard> &deck);
	static void ChooseCard(int x, int y);
	static void PickACard(std::vector<PlayerCard>& deck, ActiveMonster& monster);
	static void Cards();
	static void DrawCard(std::vector<PlayerCard>& deck);
	static void PlayCard(PlayerCard, int index, ActiveMonster& monster);
	static void Initialize(std::vector<PlayerCard> &deck);
	static void EndTurn(std::vector<PlayerCard>& deck, ActiveMonster& monster);
	static void EndRound(std::vector<PlayerCard>& deck, ActiveMonster& monster);
	static void GetRewardCards();
	static void PickRewardCard();
	static void NewRound(std::vector<PlayerCard>& deck);

	static Player& GetInstance()
	{
		static Player user = Player();
		return user;
	}
	
private:
	Player();
};