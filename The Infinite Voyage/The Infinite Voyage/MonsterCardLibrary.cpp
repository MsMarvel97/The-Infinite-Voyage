#include <iostream>
#include <string>
#include "CardTemplate.h"
#include "MonsterCardLibrary.h"


void Monsters()
{
	//Larva
	Larva->health = 6;
	Larva->damage = 2;
	Larva->strength = 1;
	Larva->title = "Larva";
	Larva->text = "Bite: Attack 2. Gain 1 Strength. Stacks up to 2 times";

	//Sentry
	Sentry->health = 8;
	Sentry->damage = 3;
	Sentry->title = "Sentry";
	Sentry->text = "Intruder Alert: Attack 3. Take 1 less damage from next player attack";

	//Engineer
	Engineer->health = 8;
	Engineer->damage = 3;
	Engineer->title = "Engineer";
	Engineer->text = "Laser Cutter: Attack 3. Player draws one fewer card next turn";
	
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


	//Trapper
	Trapper->health = 8;
	if (Trapper->attackOne == true)
	{
		Trapper->damage = 2;
	}
	if (Trapper->attackTwo == true)
	{
		Trapper->damage = 3;
	}
	Trapper->title = "Trapper";
	Trapper->text = "(Roll 1-3) Ensnare: Attack 2. Player loses 1 energy at the start of next turn. \nRoll(4-6) Whip: Attack 3.";

	//Hound
	Hound->health = 8;
	Hound->damage = 4;
	if (Hound->damage)
	{
		Hound->health--;
	}
	Hound->title = "Hound";
	Hound->text = "Savage: Attack 4. Attack self 1.";
}

