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



	//Player Upgrade Cards\\


	//Player Elite Upgrade Cards\\

}