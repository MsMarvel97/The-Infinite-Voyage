//defining MonsterCardLibrary.h
#ifndef __MonsterCardLibrary_H__
#define __MonsterCardLibrary_H__
#endif

//including PlayerCardLibrary.h
#include "PlayerCardLibrary.h"

//including vector, algorithm, random, and time.h for use by functions
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

//declaring MonsterCardLibrary class
class MonsterCardLibrary {
public:
	//declaring monster cards\\
	//declaring larva
	MonsterCard* Larva = new MonsterCard;
	//declaring sentry
	MonsterCard* Sentry = new MonsterCard;
	//declaring engineer
	MonsterCard* Engineer = new MonsterCard;
	//declaring researcher
	MonsterCard* Researcher = new MonsterCard;
	//declaring trapper
	MonsterCard* Trapper = new MonsterCard;
	//declaring hound
	MonsterCard* Hound = new MonsterCard;

	//vector to hold monster deck
	std::vector<MonsterCard>MonsterDeck;

	//function to get an instance of the monster card library
	static MonsterCardLibrary& GetInstance()
	{
		static MonsterCardLibrary Instance = MonsterCardLibrary();
		return Instance;
	}

	//function to shuffle a deck of monster cards
	static void MonsterShuffle(std::vector<MonsterCard>& deck);

private:
	//constructor for MonsterCardLibrary
	MonsterCardLibrary();
};
