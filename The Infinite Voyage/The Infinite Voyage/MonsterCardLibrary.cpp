//including MonsterCardLibrary.h
#include "MonsterCardLibrary.h"

//including iostream and string for use by later functions
#include <iostream>
#include <string>

//using std namespace
using namespace std;

//constructing MonsterCardLibrary
MonsterCardLibrary::MonsterCardLibrary()
{
	//creating monster cards\\

	//Larva\\
	//setting health of larva
	Larva->set_m_health (6);
	//setting damage of larva
	Larva->set_damage(2);
	//setting strength increase for action 1 of larva
	Larva->set_m_A1strength(1);
	//setting strength increase for action 2 of larva
	Larva->set_m_A2strength(1);
	//setting damage for action 2 of larva
	Larva->set_m_A2damage(2);
	//setting roll chance for larva. This card only has one ability, so a 6 gurantees it will hit action 1.
	Larva->set_m_rollChance(6);
	//setting title for larva
	Larva->set_title ("Larva");
	//setting ability 1 text for larva
	Larva->set_m_a1Text("Bite: Attack 2. Gain 1 Strength.");
	//setting ability 2 text for larva
	Larva->set_m_a2Text("Bite: Attack 2. Gain 1 Strength.");
	

	//Hound\\
	//setting health of hound
	Hound->set_m_health(8);
	//setting damage of hound
	Hound->set_damage(4);
	//setting action 2 damage of hound
	Hound->set_m_A2damage(4);
	//setting self-damage value of action 1
	Hound->set_m_A1selfDmg(1);
	//setting self-damage value of action 2
	Hound->set_m_A2selfDmg(1);
	//setting roll chance for larva. This card only has one ability, so a 6 gurantees it will hit action 1.
	Hound->set_m_rollChance(6);
	//setting title for hound
	Hound->set_title("Hound");
	//setting action 1 text for hound
	Hound->set_m_a1Text("Savage: Attack 4. Attack self 1.");
	//setting action 2 text for hound
	Hound->set_m_a2Text("Savage: Attack 4. Attack self 1.");
			   

	//Sentry\\
	//setting health for sentry
	Sentry->set_m_health(8);
	//setting damage for sentry
	Sentry->set_damage(3);
	//setting action 2 damage for sentry
	Sentry->set_m_A2damage(3);
	//setting action 1 damage reduction for sentry
	Sentry->set_m_A1reduceDmg(1);
	//setting action 2 damage reduction for sentry
	Sentry->set_m_A2reduceDmg(1);
	//setting roll chance for sentry. This card only has one ability, so a 6 gurantees it will hit action 1.
	Sentry->set_m_rollChance(6);
	//setting title for sentry
	Sentry->set_title("Sentry");
	//setting action 1 text for sentry
	Sentry->set_m_a1Text("Intruder Alert: Attack 3. Take 1 less damage from next player attack");
	//setting action 2 text for sentry
	Sentry->set_m_a2Text("Intruder Alert: Attack 3. Take 1 less damage from next player attack");

	//Researcher\\
	//setting health for researcher
	Researcher->set_m_health(10);
	//setting damage for researcher
	Researcher->set_damage(2);
	//setting action 2 healing value for researcher
	Researcher->set_m_A2heal(2);
	//setting roll chance for researcher. This card only has two abilities, and a 3 gives an equal chance of activating each ability.
	Researcher->set_m_rollChance(3);
	//setting title for researcher
	Researcher->set_title ("Researcher");
	//setting action 1 text for researcher
	Researcher->set_m_a1Text("Dissect: Attack 2.");
	//setting action 2 text for researcher
	Researcher->set_m_a2Text("Self-Medicate: Heal 2.");


	//filling monster deck\\
	//adding larva to monster deck
	MonsterDeck.emplace_back(*MonsterCardLibrary::Larva);
	//adding hound to monster deck
	MonsterDeck.emplace_back(*MonsterCardLibrary::Hound);
	//adding sentry to monster deck
	MonsterDeck.emplace_back(*MonsterCardLibrary::Sentry);
	//adding researcher to monster deck
	MonsterDeck.emplace_back(*MonsterCardLibrary::Researcher);
}

//function to shuffle monster cards
void MonsterCardLibrary::MonsterShuffle(std::vector<MonsterCard>& deck) {

	//obtaining a random seed for shuffle function
	auto randomizer = std::default_random_engine(std::random_device{}());
	//shuffling deck with random seed
	std::shuffle(deck.begin(), deck.end(), randomizer);

}

