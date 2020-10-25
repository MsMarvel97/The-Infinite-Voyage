#ifndef __MonsterCardLibrary_H__
#define __MonsterCardLibrary_H__
#endif
#include "PlayerCardLibrary.h"
#include <vector>
#include <algorithm>
#include <random>
#include <time.h>

class MonsterCardLibrary {
public:
	MonsterCard* Larva = new MonsterCard;
	MonsterCard* Sentry = new MonsterCard;
	MonsterCard* Engineer = new MonsterCard;
	MonsterCard* Researcher = new MonsterCard;
	MonsterCard* Trapper = new MonsterCard;
	MonsterCard* Hound = new MonsterCard;

	std::vector<MonsterCard>MonsterDeck;

	static MonsterCardLibrary& GetInstance()
	{
		static MonsterCardLibrary Instance = MonsterCardLibrary();
		return Instance;
	}

	static void MonsterShuffle(std::vector<MonsterCard>& deck);

private:
	MonsterCardLibrary();
};
