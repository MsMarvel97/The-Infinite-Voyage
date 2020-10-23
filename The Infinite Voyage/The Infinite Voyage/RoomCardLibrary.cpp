#include <iostream> 
#include <string> 
#include "CardTemplate.h" 
#include "RoomCardLibrary.h" 

using namespace std;

static void Rooms()
{
	MedicalBay->restoreHP = true;
	MedicalBay->bHPR = 1;
	MedicalBay->pHealthScale = 2;
	MedicalBay->bHealthScale = 3;
	MedicalBay->set_title("Medical Bay");
	MedicalBay->set_text("Room Effect: Upon completion of room, restore yourself to full health.\nBoss Effect: The boss heals 1 health at the end of each round.\nIncrease max player HP by 2 and max boss HP by 3 after room completion.");
		
	CrewQuarters->actFirst = true;
	CrewQuarters->drawPerR = 1;
	CrewQuarters->pHealthScale = 3;
	CrewQuarters->bHealthScale = 2;
	CrewQuarters->set_title("Crew Quarters");
	CrewQuarters->set_text("Room Effect: Enemies act first each round.\nBoss Effect: Draw +1 cards each round while fighting the boss.\nIncrease max player HP by 3 and max boss HP by 2 after room completion.");
}