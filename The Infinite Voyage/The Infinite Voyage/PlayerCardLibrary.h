//defining PlayerCardLibrary.h
#ifndef __PlayerCardLibrary_H__
#define __PlayerCardLibrary_H__
#endif

//including CardTemplate.h
#include "CardTemplate.h"

//including vector for use by later functions
#include <vector>

//declaring PlayerCardLibrary class
class PlayerCardLibrary {
public:
	//declaring player basic cards\\
	//declaring attack
	PlayerCard* attack;
	//declaring defend
	PlayerCard* defend;
	//declaring draw
	PlayerCard* draw;

	//declaring player upgrade cards\\
	//declaring heat sink
	PlayerCard* HeatSink;
	//declaring plasteel armor
	PlayerCard* PlasteelArmor;
	//declaring shield pack
	PlayerCard* ShieldPack;
	//declaring barrel
	PlayerCard* Barrel;
	//declaring scope
	PlayerCard* Scope;
	//declaring high explosive charge
	PlayerCard* HighExplosiveCharge;
	//declaring battery pack
	PlayerCard* BatteryPack;

	//declaring player decks\\
	//declaring draw pile
	std::vector<PlayerCard>DrawPile;
	//declaring discard pile
	std::vector<PlayerCard>DiscardPile;
	//declaring exhaust pile
	std::vector<PlayerCard>ExhaustPile;
	//declaring player hand
	std::vector<PlayerCard>Hand;
	//declaring upgrade cards
	std::vector<PlayerCard>UpgradeCards;

	//function to get an instance of the PlayerCardLibrary
	static PlayerCardLibrary& GetInstance()
	{
		static PlayerCardLibrary Instance = PlayerCardLibrary();
		return Instance;
	}


private:
	//constructor for the PlayerCardLibrary
	PlayerCardLibrary();

};


