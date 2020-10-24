#include <iostream>
#include <string>
#include "CardTemplate.h"
#include "PlayerCardLibrary.h"
using namespace std;

static void playerCardLibrary()
{
	//Player Basic Cards\\

	//instantiating attack card
	attack->cost = 1;
	attack->damage = 2;
	attack->title = "Attack";
	attack->text = "Deal 2 damage.";
	attack->type = "Basic";


	//instantiating defend card
	defend->cost = 1;
	defend->defense = 1;
	defend->title = "Defend";
	defend->text = "Gain 2 defense.";
	defend->type = "Basic";


	//instantiating draw card
	draw->cost = 1;
	draw->draw = 2;
	draw->title = "Draw";
	draw->text = "Draw 2 cards.";
	draw->type = "Basic";


	PlayerCards[0] = *PlayerCardLibrary::attack;
	PlayerCards[1] = *PlayerCardLibrary::defend;
	PlayerCards[2] = *PlayerCardLibrary::draw;

	//Player Upgrade Cards
	HeatSink->cost = 0;
	HeatSink->energy = 2;
	HeatSink->title = "Heat Sink";
	HeatSink->text = "Gain +2 Energy this turn";
	HeatSink->type = "Upgrade";

	PlasteelArmor->cost = 2;
	PlasteelArmor->armor = 1;
	PlasteelArmor->exhaust = true;
	PlasteelArmor->title = "Plasteel Armor";
	PlasteelArmor->text = "Gain 1 Armor. Exhaust.";
	PlasteelArmor->type = "Upgrade";

	ShieldPack->cost = 1;
	ShieldPack->defense = 4;
	ShieldPack->title = "Shield Pack";
	ShieldPack->text = "Gain 4 defense.";
	ShieldPack->type = "Upgrade";

	Barrel->cost = 1;
	Barrel->damage = 6;
	Barrel->defense = -1;
	Barrel->title = "Barrel";
	Barrel->text = "Deal 6 Damage and lose 1 Defense this round";
	Barrel->type = "Upgrade";

	Scope->cost = 1;
	Scope->damage = 3;
	Scope->draw = 1;
	Scope->title = "Scope";
	Scope->text = "Deal 3 damage. Draw 1 card.";
	Scope->type = "Upgrade";

	HighExplosiveCharge->cost = 1;
	HighExplosiveCharge->damage = 6;
	HighExplosiveCharge->exhaust = true;
	HighExplosiveCharge->title = "High-Explosive Charge";
	HighExplosiveCharge->text = "Deal 6 Damage. Exhaust.";
	HighExplosiveCharge->type = "Upgrade";

	BatteryPack->cost = 1;
	BatteryPack->draw = 3;
	BatteryPack->title = "Battery Pack";
	BatteryPack->text = "Draw 3 cards";
	BatteryPack->type = "Upgrade";


	//Player Elite Upgrade Cards

}