#include <iostream>
#include <string>
#include "CardTemplate.h"
#include "BossCardLibrary.h"

using namespace std;

static void bossCardLibrary()
{
	//boss basic
	RendingClaws->damage = (2 * CR) + 2;
	RendingClaws->title = "Rending Claws";
	RendingClaws->text = "Attack player for 2 + 2 x Challenge Rating";
	
	TwistedLash->damage = 3;
	TwistedLash->title = "Twisted Lash";
	TwistedLash->text = "Attack player for 3 damage. Player loses 3 strength until end of next turn.";

	Evolve->armor = 1 + CR;
	Evolve->title = "Evolve";
	Evolve->text = "Gain armor equal to 1 + Challenge Rating. Lose  this armor at the end of the next player phase.";


	//boss advanced
	FueledRage->damage = 2 + CR;
	FueledRage->heal = CR;
	FueledRage->title = "Fueled Rage";
	FueledRage->text = "Attack player for 2 + Challenge Rating. Heal equal to Challenge Rating.";

	Mutate->heal = CR;
	Mutate->strength = 1;
	Mutate->armor = 1;
	Mutate->title = "Mutate";
	Mutate->text = "Heal equal to Challenge Rating. Gain 1 strength and 1 armor.";
}