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

	//creating player basic deck
	BasicDeck[0] = *PlayerCardLibrary::attack;
	BasicDeck[1] = *PlayerCardLibrary::attack;
	BasicDeck[2] = *PlayerCardLibrary::attack;
	BasicDeck[3] = *PlayerCardLibrary::attack;
	BasicDeck[4] = *PlayerCardLibrary::attack;
	BasicDeck[5] = *PlayerCardLibrary::attack;
	BasicDeck[6] = *PlayerCardLibrary::defend;
	BasicDeck[7] = *PlayerCardLibrary::defend;
	BasicDeck[8] = *PlayerCardLibrary::defend;
	BasicDeck[9] = *PlayerCardLibrary::draw;



	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	DrawPile.emplace_back(*PlayerCardLibrary::draw);




	//Player Upgrade Cards
	HeatSink = new PlayerCard();
	HeatSink->set_cost(0);
	HeatSink->set_energy(2);
	HeatSink->set_title("Heat Sink");
	HeatSink->set_text("Gain +2 energy this turn.");
	HeatSink->set_type("Upgrade");

	Overload = new PlayerCard();
	Overload->set_cost(Overload->get_energy());
	Overload->set_damage(Overload->get_energy() * 3);
	Overload->set_title("Overload");
	Overload->set_text("Spend all remaining energy and deal damage equal to 3 x (remaining energy)");
	Overload->set_type("Upgrade");

	PlasteelArmor = new PlayerCard();
	PlasteelArmor->set_cost(2);
	PlasteelArmor->set_armor(1);
	PlasteelArmor->set_exhaust(true);
	PlasteelArmor->set_title("Plasteel Armor");
	PlasteelArmor->set_text("Gain 1 armor. Exhaust");
	PlasteelArmor->set_type("Upgrade");

	ShieldPack = new PlayerCard();
	ShieldPack->set_cost(1);
	ShieldPack->set_defense(4);
	ShieldPack->set_title("Shield Pack");
	ShieldPack->set_text("Gain 4 defense.");
	ShieldPack->set_type("Upgrade");

	Barrel = new PlayerCard();
	Barrel->set_cost(1);
	Barrel->set_damage(6);
	Barrel->set_defense(-1);
	Barrel->set_title("Barrel");
	Barrel->set_text("Deal 6 damage and lose 1 defense.");
	Barrel->set_type("Upgrade");

	Scope = new PlayerCard();
	Scope->set_cost(1);
	Scope->set_damage(3);
	Scope->set_draw(1);
	Scope->set_title("Scope");
	Scope->set_text("Deal 3 damage and draw 1 card");
	Scope->set_type("Upgrade");

	HighExplosiveCharge = new PlayerCard();
	HighExplosiveCharge->set_cost(1);
	HighExplosiveCharge->set_damage(6);
	HighExplosiveCharge->set_exhaust(true);
	HighExplosiveCharge->set_title("High-Explosive Charge");
	HighExplosiveCharge->set_text("Deal 6 damage. Exhaust");
	HighExplosiveCharge->set_type("Upgrade");

	BatteryPack = new PlayerCard();
	BatteryPack->set_cost(1);
	BatteryPack->set_draw(3);
	BatteryPack->set_title("Battery Pack");
	BatteryPack->set_text("Draw 3 cards.");
	BatteryPack->set_type("Upgrade");


	//creating vector of upgrade cards
	UpgradeCards.emplace_back(*PlayerCardLibrary::HeatSink);
	UpgradeCards.emplace_back(*PlayerCardLibrary::Overload);
	UpgradeCards.emplace_back(*PlayerCardLibrary::PlasteelArmor);
	UpgradeCards.emplace_back(*PlayerCardLibrary::ShieldPack);
	UpgradeCards.emplace_back(*PlayerCardLibrary::Barrel);
	UpgradeCards.emplace_back(*PlayerCardLibrary::Scope);
	UpgradeCards.emplace_back(*PlayerCardLibrary::BatteryPack);


	//creating array of instantiated player cards
	PlayerCards[0] = *PlayerCardLibrary::attack;
	PlayerCards[1] = *PlayerCardLibrary::defend;
	PlayerCards[2] = *PlayerCardLibrary::draw;
	PlayerCards[3] = *PlayerCardLibrary::HeatSink;
	PlayerCards[4] = *PlayerCardLibrary::Overload;
	PlayerCards[5] = *PlayerCardLibrary::PlasteelArmor;
	PlayerCards[6] = *PlayerCardLibrary::ShieldPack;
	PlayerCards[7] = *PlayerCardLibrary::Barrel;
	PlayerCards[8] = *PlayerCardLibrary::Scope;
	PlayerCards[9] = *PlayerCardLibrary::BatteryPack;

	//Player Elite Upgrade Cards\\

	/*Barrel->cost = 1;
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
	BatteryPack->type = "Upgrade";*/


	//Player Elite Upgrade Cards

}