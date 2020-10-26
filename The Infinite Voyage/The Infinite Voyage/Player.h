//defining Player.h
#ifndef __Player_H__
#define __Player_H__
#endif

//including MonsterAction.h
#include "MonsterAction.h"

//including vector, algorithm, and random for use by later functions
#include <vector>
#include <algorithm>
#include <random>

//declaring player class
class Player {
//setting public variables and functions
public:
	//setting integer variables to handle player stats
	int health = 20, energy = 3, armor = 0, defense = 0, strength = 0;
	//initializing bool to flag the end of a turn and initializing it to false
	bool endRound = false;

	//getters and setters for the above variables
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


	//Player Functions\\

	//function shuffles the PlayerCard deck that is passed to it
	static void Shuffle (std::vector<PlayerCard> &deck);
	
	//function to handle picking cards
	static void PickACard(std::vector<PlayerCard>& deck, ActiveMonster& monster);
	
	//function to handle drawing cards 
	static void DrawCard(std::vector<PlayerCard>& deck);

	//function to handle playing cards
	static void PlayCard(PlayerCard, int index, ActiveMonster& monster);

	//function to handle initializing the player deck at the start of the game
	static void Initialize(std::vector<PlayerCard> &deck);

	//function to handle the end of a turn
	static void EndTurn(std::vector<PlayerCard>& deck, ActiveMonster& monster);

	//function to handle the end of a round after monster is defeated
	static void EndRound(std::vector<PlayerCard>& deck, ActiveMonster& monster);

	//function to handle getting reward cards to select from
	static void GetRewardCards();

	//functin to handle picking reward cards
	static void PickRewardCard();

	//function to handle redrawing player hand at the start of a round
	static void NewRound(std::vector<PlayerCard>& deck);


	//function to get an instance of the player class so it can be operated on by other functions
	static Player& GetInstance()
	{
		static Player user = Player();
		return user;
	}

//private functions for player class
private:
	//constructor for player class
	Player();
};