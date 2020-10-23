#include <iostream> 
#include <string> 
#include "RoomCardLibrary.h" 

using namespace std;

static void Rooms()
{
	MedicalBay->set_m_restoreHP (true);
	MedicalBay->set_m_bHPR (1);
	MedicalBay->set_m_pHealthScale (2);
	MedicalBay->set_m_bHealthScale (3);
	MedicalBay->set_title("Medical Bay");
	MedicalBay->set_text("Room Effect: Upon completion of room, restore yourself to full health.\nBoss Effect: The boss heals 1 health at the end of each round.\nIncrease max player HP by 2 and max boss HP by 3 after room completion.");
		
	CrewQuarters->set_m_actFirst (true);
	CrewQuarters->set_m_drawPerR (1);
	CrewQuarters->set_m_pHealthScale (3);
	CrewQuarters->set_m_bHealthScale (2);
	CrewQuarters->set_title("Crew Quarters");
	CrewQuarters->set_text("Room Effect: Enemies act first each round.\nBoss Effect: Draw +1 cards each round while fighting the boss.\nIncrease max player HP by 3 and max boss HP by 2 after room completion.");
}