#ifndef __PlayerCardLibrary_H__
#define __PlayerCardLibrary_H__
#endif
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

	PlayerCard PlayerCards[10];
	static PlayerCardLibrary& GetInstance()
	{
		static PlayerCardLibrary Instance = PlayerCardLibrary();
		return Instance;
	}


private:

	PlayerCardLibrary();

};
