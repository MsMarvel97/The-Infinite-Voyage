#include <iostream> 
#include <string> 
#include "BossCardLibrary.h" 

using namespace std;

Boss::Boss()
{
	//boss basic
	rendingClaws->set_damage(2 + (2 * m_CR));
	rendingClaws->set_text("Rending Claws: Attack player for 2 + 2 x Challenge Rating");

	twistedLash->set_damage(3);
	twistedLash->set_strength(twistedLash->get_strength() - 3);
	twistedLash->set_text("Twisted Lash: Attack player for 3 damage. Player loses 3 strength until end of next turn.");

	evolve->set_armor(1 + m_CR);
	evolve->set_text("Evolve: Gain defense equal to 1 + Challenge Rating.");

	BossDraw.emplace_back(*rendingClaws);
	BossDraw.emplace_back(*fueledRage);
	BossDraw.emplace_back(*evolve);

	//boss advanced 
	fueledRage->set_damage(2 + m_CR);
	fueledRage->set_heal(m_CR);
	fueledRage->set_text("Fueled Rage: Attack player for 2 + Challenge Rating. Heal equal to Challenge Rating.");

	mutate->set_heal(m_CR);
	mutate->set_strength(1);
	mutate->set_armor(1);
	mutate->set_text("Mutate: Heal equal to Challenge Rating. Gain 1 strength and 1 armor.");
}

void Boss::DrawBossCard(std::vector<BossCard>& deck) {

	Boss& alien = Boss::GetInstance();

	if (alien.BossDraw.size() == 0 && alien.BossDiscard.size() > 0)
	{

		int x = alien.BossDiscard.size() - 1;

		for (int y = 0; y <= x; y++) {
			//refill deck from discard
			alien.BossDraw.emplace_back(alien.BossDiscard[0]);
			alien.BossDiscard.erase(alien.BossDiscard.begin() + 0);

		}
		BossShuffle(deck);
		DrawBossCard(deck);
	}
	else if (alien.BossDraw.size() > 0) {
		alien.active = alien.BossDraw[0];
		alien.BossDraw.erase(alien.BossDraw.begin() + 0);
		PlayBossCard(alien.active);
	}
}

void Boss::PlayBossCard(BossCard active) {

	Boss& alien = Boss::GetInstance();
	Player& user = Player::GetInstance();
	
	alien.set_m_def(active.get_defense());
	alien.set_m_hp(alien.get_m_hp() + active.get_heal());
	user.set_health(user.get_health() - active.get_damage());
	alien.set_lastBCard(active.get_text());
	alien.BossDiscard.emplace_back(alien.BossDraw[0]);
	alien.BossDraw.erase(alien.BossDraw.begin() + 0);
	
}

void Boss::BossShuffle(std::vector<BossCard>& deck) {
	auto randomizer = std::default_random_engine(std::random_device{}());
	std::shuffle(deck.begin(), deck.end(), randomizer);
}


//function to receive damage for monster and check if it has died\\

bool Boss::ReceiveDamage(int pDmg) {
	Boss& alien = Boss::GetInstance();
	//bool to check if monster is dead
	bool dead = false;
	//integer to hold damage dealt by player
	int receiveddamage = pDmg;

	//apply player damage\\
	//checking if monster has damage reduction available
	if (alien.get_m_def() > 0)
	{
		//reducing monster health value by player damage value - monster damage reduction
		alien.set_m_hp(alien.get_m_hp() - (receiveddamage - alien.get_m_def()));
	}

	else
	{
		//reducing monster health value by player damage value
		alien.set_m_hp(alien.get_m_hp() - receiveddamage);
	}
	//end apply player damage


	//check if monster has 0 or fewer health
	if (alien.get_m_hp() <= 0)
	{
		//returning bool to show that monster is dead
		return dead = true;
	}

}