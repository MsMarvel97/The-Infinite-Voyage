#include <iostream> 
#include <string> 
#include "BossCardLibrary.h" 

using namespace std;

Boss::Boss()
{
	//boss basic cards\\

	//setting card effects of rending claws
	rendingClaws->set_damage(2 + (2 * m_CR));
	rendingClaws->set_text("Rending Claws: Attack player for 2 + 2 x Challenge Rating");

	//setting card effects of twisted lash
	twistedLash->set_damage(3);
	twistedLash->set_strength(twistedLash->get_strength() - 3);
	twistedLash->set_text("Twisted Lash: Attack player for 3 damage. Player loses 3 strength until end of next turn.");

	//setting card effects of evolve
	evolve->set_armor(1 + m_CR);
	evolve->set_text("Evolve: Gain defense equal to 1 + Challenge Rating.");


	//boss advanced cards\\
	
	//setting card effects of fueled rage
	fueledRage->set_damage(2 + m_CR);
	fueledRage->set_heal(m_CR);
	fueledRage->set_text("Fueled Rage: Attack player for 2 + Challenge Rating. Heal equal to Challenge Rating.");

	//setting card effects of mutate
	mutate->set_heal(m_CR);
	mutate->set_strength(1);
	mutate->set_armor(1);
	mutate->set_text("Mutate: Heal equal to Challenge Rating. Gain 1 strength and 1 armor.");

	//setting boss card deck\\
	//adding rending claws to boss card deck
	BossDraw.emplace_back(*rendingClaws);
	//adding fueled rage to boss card deck
	BossDraw.emplace_back(*fueledRage);
	//adding evolve to boss card deck
	BossDraw.emplace_back(*evolve);

}

//function to handle drawing a boss card
void Boss::DrawBossCard(std::vector<BossCard>& deck) {

	//getting an instance of the boss class
	Boss& alien = Boss::GetInstance();

	//checking if there are still cards to draw from boss draw pile and refilling the draw pile from the discard pile if not
	if (alien.BossDraw.size() == 0 && alien.BossDiscard.size() > 0)
	{
		//int to hold size of boss discard pile - 1 for index purposes
		int x = alien.BossDiscard.size() - 1;

		//moving cards from discard to draw until there are no cards left in discard
		for (int y = 0; y <= x; y++) {
			//refill deck from discard
			alien.BossDraw.emplace_back(alien.BossDiscard[0]);
			alien.BossDiscard.erase(alien.BossDiscard.begin() + 0);

		}
		//shuffling boss deck
		BossShuffle(deck);
		//calling draw card function again
		DrawBossCard(deck);
	}
	//if there are still cards in draw pile, draws a card and plays one
	else if (alien.BossDraw.size() > 0) {
		//drawing a card from the boss draw pile and setting it to active card
		alien.active = alien.BossDraw[0];
		//sending active card to PlayBossCard function
		PlayBossCard(alien.active);
	}
}

//function to play a boss card
void Boss::PlayBossCard(BossCard active) {

	//getting an instance of the boss
	Boss& alien = Boss::GetInstance();
	//getting an instance of the palyer
	Player& user = Player::GetInstance();

	//increasing boss defense by value of active card
	alien.set_m_def(alien.get_m_def() + active.get_defense());
	//increasing boss health by value of active card
	alien.set_m_hp(alien.get_m_hp() + active.get_heal());
	//reducing player health by damage value of active card
	user.set_health(user.get_health() - active.get_damage());
	//setting text for last boss card played to text vale of active card
	alien.set_lastBCard(active.get_text());
	//putting active card into discard pile
	alien.BossDiscard.emplace_back(alien.BossDraw[0]);
	//removing active card from boss draw pile
	alien.BossDraw.erase(alien.BossDraw.begin() + 0);
	
}

//function to shuffle boss cards
void Boss::BossShuffle(std::vector<BossCard>& deck) {
	//seed for random shuffling
	auto randomizer = std::default_random_engine(std::random_device{}());
	//shuffling boss cards using random seed
	std::shuffle(deck.begin(), deck.end(), randomizer);
}


//function to receive damage for boss and check if it has died
bool Boss::ReceiveDamage(int pDmg) {
	Boss& alien = Boss::GetInstance();
	//bool to check if boss is dead
	bool dead = false;
	//integer to hold damage dealt by player
	int receiveddamage = pDmg;

	//apply player damage\\
	//checking if boss has defense available
	if (alien.get_m_def() > 0)
	{
		//reducing boss health value by player damage value - boss defense value
		alien.set_m_hp(alien.get_m_hp() - (receiveddamage - alien.get_m_def()));
	}

	else
	{
		//reducing boss health value by player damage value
		alien.set_m_hp(alien.get_m_hp() - receiveddamage);
	}
	//end apply player damage


	//check if boss has 0 or fewer health
	if (alien.get_m_hp() <= 0)
	{
		//returning bool to show that boss is dead
		return dead = true;
	}

}