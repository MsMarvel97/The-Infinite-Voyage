#include <iostream>
#include <string>
#include "PlayerCardLibrary.h"
using namespace std;

PlayerCardLibrary::PlayerCardLibrary()
{
	//Player Basic Cards\\

	//instantiating attack card
	attack = new PlayerCard();
	attack->set_cost(1);
	attack->set_damage (2);
	attack->set_title ("Attack");
	attack->set_text ("Deal 2 damage.");
	attack->set_type ("Basic");

	//instantiating defend card
	defend = new PlayerCard();
	defend->set_cost (1);
	defend->set_defense (1);
	defend->set_title ("Defend");
	defend->set_text ("Gain 2 defense.");
	defend->set_type ("Basic");


	//instantiating draw card
	draw = new PlayerCard();
	draw->set_cost (1);
	draw->set_draw (2);
	draw->set_title ("Draw");
	draw->set_text ("Draw 2 cards.");
	draw->set_type ("Basic");



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