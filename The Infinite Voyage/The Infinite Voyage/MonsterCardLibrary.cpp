#include <iostream>
#include <string>
#include "CardTemplate.h"
#include "MonsterCardLibrary.h"

using namespace std;

static void Monsters()
{
	Larva->health = 6;
	Larva->set_damage(2);
	Larva->set_strength(1);
	Larva->title = "Larva";
	Larva->set_text("Bite: Attack 2. Gain 1 Strength. Stacks up to 2 times");

	
	//Sentry->health = 8;
	//Sentry->set_damage(3);
	//Sentry->title = "Sentry";
	//Sentry->set_text("Intruder Alert: Attack 3. Take 1 less damage from next player attack");

	
	//Engineer->health = 8;
	//Engineer->set_damage(3);
	//Engineer->title = "Engineer";
	//Engineer->set_text("Laser Cutter: Attack 3. Player draws one fewer card next turn");

	//Researcher
	Researcher->health = 10;
	if (Researcher->attackOne == true)
	{
		Researcher->set_damage(2);
	}
	if (Researcher->attackTwo == true)
	{
		Researcher->set_heal(2);
	}
	Researcher->title = "Researcher";
	Researcher->set_text("(Roll 1-3) Dissect: Attack 2. \nRoll(4-6) Self-Medicate: Heal 2.");


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

	//Hound
	Hound->health = 8;
	Hound->set_damage(4);
	if (Hound->damage)
	{
		Hound->health--;
	}
	Hound->title = "Hound";
	Hound->set_text("Savage: Attack 4. Attack self 1.");
	
	//Researcher
	Researcher->health = 10;
	if (Researcher->attackOne == true)
	{
		Researcher->damage = 2;
	}
	if (Researcher->attackTwo == true)
	{
		Researcher->heal = 2;
	}
	Researcher->title = "Researcher";
	Researcher->text = "(Roll 1-3) Dissect: Attack 2. \nRoll(4-6) Self-Medicate: Heal 2.";

	


}

