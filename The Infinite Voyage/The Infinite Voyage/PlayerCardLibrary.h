#ifndef __PlayerCardLibrary_H__
#define __PlayerCardLibrary_H__
#endif
#include "CardTemplate.h"

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

	PlayerCardLibrary();
};

