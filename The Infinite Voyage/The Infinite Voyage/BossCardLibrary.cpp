#include <iostream> 
#include <string> 
#include "CardTemplate.h" 
#include "BossCardLibrary.h" 

using namespace std;

static void bossCardLibrary()
{
	//boss basic

	RendingClaws->set_damage(2 + (2 * CR));
	RendingClaws->set_title("Rending Claws");
	RendingClaws->set_text("Attack player for 2 + 2 x Challenge Rating");

	TwistedLash->set_damage(3);
	TwistedLash->set_strength(TwistedLash->get_strength() - 3);
	TwistedLash->set_title("Twisted Lash");
	TwistedLash->set_text("Attack player for 3 damage. Player loses 3 strength until end of next turn.");

	Evolve->set_armor(1 + CR);
	Evolve->set_title("Evolve");
	Evolve->set_text("Gain armor equal to 1 + Challenge Rating. Lose this armor at the end of the next player phase.");


	//boss advanced 
	FueledRage->set_damage(2 + CR);
	FueledRage->set_heal(CR);
	FueledRage->set_title("Fueled Rage");
	FueledRage->set_text("Attack player for 2 + Challenge Rating. Heal equal to Challenge Rating.");

	Mutate->set_heal(CR);
	Mutate->set_strength(CR);
	Mutate->set_armor(1);
	Mutate->set_title("Mutate");
	Mutate->set_text("Heal equal to Challenge Rating. Gain 1 strength and 1 armor.");
}