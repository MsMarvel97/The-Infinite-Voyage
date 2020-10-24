#ifndef __PlayerCardLibrary_H__
#define __PlayerCardLibrary_H__
#endif
#include <vector>
#include "CardTemplate.h"

//player basic


class PlayerCardLibrary {
public:
	PlayerCard* attack;
	PlayerCard* defend;
	PlayerCard* draw;

	PlayerCard* HeatSink;
	PlayerCard* Overload;
	PlayerCard* PlasteelArmor;
	PlayerCard* ShieldPack;
	PlayerCard* Barrel;
	PlayerCard* Scope;
	PlayerCard* HighExplosiveCharge;
	PlayerCard* BatteryPack;

	PlayerCard BasicDeck[10];
	PlayerCard PlayerCards[10];

	std::vector<PlayerCard>DrawPile;
	std::vector<PlayerCard>DiscardPile;
	std::vector<PlayerCard>ExhaustPile;
	std::vector<PlayerCard>Hand;
	std::vector<PlayerCard>UpgradeCards;

	static PlayerCardLibrary& GetInstance()
	{
		static PlayerCardLibrary Instance = PlayerCardLibrary();
		return Instance;
	}


private:

	PlayerCardLibrary();

};


