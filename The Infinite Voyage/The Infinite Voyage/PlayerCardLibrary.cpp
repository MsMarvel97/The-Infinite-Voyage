#include <iostream>
#include <string>
#include "PlayerCardLibrary.h"
using namespace std;

PlayerCardLibrary::PlayerCardLibrary()
{
	//Player Basic Cards\\

	//instantiating attack card
	attack = new PlayerCard();
	//setting cost of attack card
	attack->set_cost(1);
	//setting damage of attack card
	attack->set_damage (2);
	//setting title of attack card
	attack->set_title ("Attack");
	//setting text for attack card
	attack->set_text ("Deal 2 damage.");
	//setting type for attack card
	attack->set_type ("Basic");

	//instantiating defend card
	defend = new PlayerCard();
	//setting cost of defend card
	defend->set_cost (1);
	//setting defense for defend card
	defend->set_defense (2);
	//setting title for defend card
	defend->set_title ("Defend");
	//setting text for defend card
	defend->set_text ("Gain 2 defense.");
	//setting type for defend card
	defend->set_type ("Basic");


	//instantiating draw card
	draw = new PlayerCard();
	//setting cost for draw card
	draw->set_cost (1);
	//setting card draw value for draw card
	draw->set_draw (2);
	//setting title for draw card
	draw->set_title ("Draw");
	//setting text for draw card
	draw->set_text ("Draw 2 cards.");
	//setting type for draw card
	draw->set_type ("Basic");


	//creating player basic deck\\
	//adding 7 copies of attack to player draw pile
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	DrawPile.emplace_back(*PlayerCardLibrary::attack);
	//adding 3 copies of defend to player draw pile
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	DrawPile.emplace_back(*PlayerCardLibrary::defend);
	//adding 1 copy of draw to player draw pile
	DrawPile.emplace_back(*PlayerCardLibrary::draw);


	//Player Upgrade Cards\\

	//instantiating heat sink card
	HeatSink = new PlayerCard();
	//setting cost for heat sink card
	HeatSink->set_cost(0);
	//setting energy generation for heat sink card
	HeatSink->set_energy(2);
	//setting title for heat sink card
	HeatSink->set_title("Heat Sink");
	//setting text for heat sink card
	HeatSink->set_text("Gain +2 energy this turn.");
	//setting type for heat sink card
	HeatSink->set_type("Upgrade");

	//instantiating plasteel armor card
	PlasteelArmor = new PlayerCard();
	//setting cost for plasteel armor card
	PlasteelArmor->set_cost(2);
	//setting armor value for plasteel armor card
	PlasteelArmor->set_armor(1);
	//setting exhaust to true for plasteel armor card
	PlasteelArmor->set_exhaust(true);
	//setting title for plasteel armor card
	PlasteelArmor->set_title("Plasteel Armor");
	//setting text for plasteel armor card
	PlasteelArmor->set_text("Gain 1 armor. Exhaust");
	//setting type for plasteel armor card
	PlasteelArmor->set_type("Upgrade");

	//instantiating shield pack card
	ShieldPack = new PlayerCard();
	//setting cost for shield pack card
	ShieldPack->set_cost(1);
	//setting defense value for shield pack card
	ShieldPack->set_defense(4);
	//setting title for shield pack card
	ShieldPack->set_title("Shield Pack");
	//setting text for shield pack card
	ShieldPack->set_text("Gain 4 defense.");
	//setting type for shield pack card
	ShieldPack->set_type("Upgrade");

	//instantiating barrel card
	Barrel = new PlayerCard();
	//setting cost for barrel card
	Barrel->set_cost(1);
	//setting damage for barrel card
	Barrel->set_damage(6);
	//setting defense value for barrel card
	Barrel->set_defense(-1);
	//setting title for barrel card
	Barrel->set_title("Barrel");
	//setting text for barrel card
	Barrel->set_text("Deal 6 damage and lose 1 defense.");
	//setting type for barrel card
	Barrel->set_type("Upgrade");

	//instantiating scope card
	Scope = new PlayerCard();
	//setting cost for scope card
	Scope->set_cost(1);
	//setting damage for scope card
	Scope->set_damage(3);
	//setting draw value for scope card
	Scope->set_draw(1);
	//setting title for scope card
	Scope->set_title("Scope");
	//setting text for scope card
	Scope->set_text("Deal 3 damage and draw 1 card");
	//setting type for scope card
	Scope->set_type("Upgrade");

	//instantiating high explosive charge card
	HighExplosiveCharge = new PlayerCard();
	//setting cost for high explosive charge card
	HighExplosiveCharge->set_cost(1);
	//setting damage for high explosive charge card
	HighExplosiveCharge->set_damage(6);
	//setting exhaust to true for high explosive charge card
	HighExplosiveCharge->set_exhaust(true);
	//setting title for high explosive charge card
	HighExplosiveCharge->set_title("High-Explosive Charge");
	//setting text for high explosive charge card
	HighExplosiveCharge->set_text("Deal 6 damage. Exhaust");
	//setting type for high explosive charge card
	HighExplosiveCharge->set_type("Upgrade");

	//instantiating battery pack card
	BatteryPack = new PlayerCard();
	//setting cost of battery pack card
	BatteryPack->set_cost(1);
	//setting draw value for battery pack card
	BatteryPack->set_draw(3);
	//setting title for battery pack card
	BatteryPack->set_title("Battery Pack");
	//setting text for battery pack card
	BatteryPack->set_text("Draw 3 cards.");
	//setting type for battery pack card
	BatteryPack->set_type("Upgrade");


	//filling UpgradeCards deck\\
	//adding heat sink to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::HeatSink);
	//adding plasteel armor to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::PlasteelArmor);
	//adding shield pack to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::ShieldPack);
	//adding barrel to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::Barrel);
	//adding scope to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::Scope);
	//adding high explosive charge to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::HighExplosiveCharge);
	//adding battery pack to UpgradeCards deck
	UpgradeCards.emplace_back(*PlayerCardLibrary::BatteryPack);


}