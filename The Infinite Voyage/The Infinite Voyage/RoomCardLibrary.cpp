#include <iostream> 
#include <string> 
#include "RoomCardLibrary.h" 

using namespace std;

RoomCardLibrary::RoomCardLibrary()
{
	medicalBay->set_m_restoreHP (true);
	medicalBay->set_m_bHPR (1);
	medicalBay->set_m_pHealthScale (2);
	medicalBay->set_m_bHealthScale (3);
	medicalBay->set_title("Medical Bay");
	medicalBay->set_text("Room Effect: Upon completion of room, restore yourself to full health.\nBoss Effect: The boss heals 1 health at the end of each round.\nIncrease max player HP by 2 and max boss HP by 3 after room completion.");
		
	crewQuarters->set_m_actFirst (true);
	crewQuarters->set_m_drawPerR (1);
	crewQuarters->set_m_pHealthScale (3);
	crewQuarters->set_m_bHealthScale (2);
	crewQuarters->set_title("Crew Quarters");
	crewQuarters->set_text("Room Effect: Enemies act first each round.\nBoss Effect: Draw +1 cards each round while fighting the boss.\nIncrease max player HP by 3 and max boss HP by 2 after room completion.");
}