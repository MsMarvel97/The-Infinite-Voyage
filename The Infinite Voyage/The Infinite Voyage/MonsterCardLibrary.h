#ifndef __MonsterCardLibrary_H__
#define __MonsterCardLibrary_H__
#endif
#include "PlayerCardLibrary.h"


class MonsterCardLibrary {
public:
	MonsterCard* Larva = new MonsterCard;
	MonsterCard* Sentry = new MonsterCard;
	MonsterCard* Engineer = new MonsterCard;
	MonsterCard* Researcher = new MonsterCard;
	MonsterCard* Trapper = new MonsterCard;
	MonsterCard* Hound = new MonsterCard;
	static MonsterCardLibrary& GetInstance()
	{
		static MonsterCardLibrary Instance = MonsterCardLibrary();
		return Instance;
	}
	MonsterCard MonsterCards[5];

private:
	MonsterCardLibrary();
};
