#include <iostream> 
#include <string> 
#include "BossCardLibrary.h" 

using namespace std;

Boss::Boss()
{
	//boss basic
	rendingClaws->set_damage(2 + (2 * m_CR));
	rendingClaws->set_title("Rending Claws");
	rendingClaws->set_text("Attack player for 2 + 2 x Challenge Rating");

	twistedLash->set_damage(3);
	twistedLash->set_strength(twistedLash->get_strength() - 3);
	twistedLash->set_title("Twisted Lash");
	twistedLash->set_text("Attack player for 3 damage. Player loses 3 strength until end of next turn.");

	evolve->set_armor(1 + m_CR);
	evolve->set_title("Evolve");
	evolve->set_text("Gain armor equal to 1 + Challenge Rating. Lose this armor at the end of the next player phase.");


	//boss advanced 
	fueledRage->set_damage(2 + m_CR);
	fueledRage->set_heal(m_CR);
	fueledRage->set_title("Fueled Rage");
	fueledRage->set_text("Attack player for 2 + Challenge Rating. Heal equal to Challenge Rating.");

	mutate->set_heal(m_CR);
	mutate->set_strength(m_CR);
	mutate->set_armor(1);
	mutate->set_title("Mutate");
	mutate->set_text("Heal equal to Challenge Rating. Gain 1 strength and 1 armor.");
}