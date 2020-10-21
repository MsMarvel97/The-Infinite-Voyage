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



	//Player Upgrade Cards\\


	//Player Elite Upgrade Cards\\

}