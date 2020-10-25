#include <iostream>
#include <string>
#include "MonsterCardLibrary.h"

using namespace std;

MonsterCardLibrary::MonsterCardLibrary()
{
	//Larva
	Larva->set_m_health (6);
	Larva->set_damage(2);
	Larva->set_strength(1);
	Larva->set_title ("Larva");
	Larva->set_text("Bite: Attack 2. Gain 1 Strength. Stacks up to 2 times");

	//Hound
	Hound->set_m_health(8);
	Hound->set_damage(4);
	Hound->set_m_selfDmg(1);
	Hound->set_title("Hound");
	Hound->set_text("Savage: Attack 4. Attack self 1.");
			   

	Sentry->set_m_health(8);
	Sentry->set_damage(3);
	Sentry->set_defense(1);
	Sentry->set_title("Sentry");
	Sentry->set_text("Intruder Alert: Attack 3. Take 1 less damage from next player attack");

	MonsterDeck[0] = *MonsterCardLibrary::Larva;
	MonsterDeck[1] = *MonsterCardLibrary::Hound;
	MonsterDeck[2] = *MonsterCardLibrary::Sentry;
	
	//Engineer->health = 8;
	//Engineer->set_damage(3);
	//Engineer->title = "Engineer";
	//Engineer->set_text("Laser Cutter: Attack 3. Player draws one fewer card next turn");

	//Researcher
	//Researcher->set_m_health(10);
	//if (Researcher->get_m_attackOne == true)
	//{
	//	Researcher->set_damage(2);
	//}
	//if (Researcher->attackTwo == true)
	//{
	//	Researcher->set_heal(2);
	//}
	//Researcher->title = "Researcher";
	//Researcher->set_text("(Roll 1-3) Dissect: Attack 2. \nRoll(4-6) Self-Medicate: Heal 2.");


	//Trapper
	//Trapper->health = 8;
	//if (Trapper->attackOne == true)
	//{
	//	Trapper->set_damage(2);
	//}
	//if (Trapper->attackTwo == true)
	//{
	//	Trapper->set_damage(3);
	//}
	//Trapper->title = "Trapper";
	//Trapper->text = "(Roll 1-3) Ensnare: Attack 2. Player loses 1 energy at the start of next turn. \nRoll(4-6) Whip: Attack 3.";


	
	////Researcher
	//Researcher->health = 10;
	//if (Researcher->attackOne == true)
	//{ 
	//	Researcher->damage = 2;
	//}
	//if (Researcher->attackTwo == true)
	//{
	//	Researcher->heal = 2;
	//}
	//Researcher->title = "Researcher";
	//Researcher->text = "(Roll 1-3) Dissect: Attack 2. \nRoll(4-6) Self-Medicate: Heal 2.";

	//


}

void MonsterCardLibrary::MonsterShuffle(std::vector<MonsterCard>& deck) {

	auto randomizer = std::default_random_engine(std::random_device{}());

	std::shuffle(deck.begin(), deck.end(), randomizer);

}

