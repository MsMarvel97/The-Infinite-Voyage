//including RoomCardLibrary.h
#include "RoomCardLibrary.h" 

//including iostream and string
#include <iostream> 
#include <string> 

//using std namespace
using namespace std;

//constructing RoomCardLibrary
RoomCardLibrary::RoomCardLibrary()
{
	//setting full health restore to true for medical bay
	medicalBay->set_m_restoreHP (true);
	//setting boss heal per round to 1 for medical bay
	medicalBay->set_m_bHPR (1);
	//setting player health scaling to 2 for medical bay
	medicalBay->set_m_pHealthScale (2);
	//setting boss health scaling to 3 for medical bay
	medicalBay->set_m_bHealthScale (3);
	//setting title for medical bay
	medicalBay->set_title("Medical Bay");
	//setting text for medical bay
	medicalBay->set_text("Room Effect: Upon completion of room, restore yourself to full health.\nBoss Effect: The boss heals 1 health at the end of each round.\nIncrease max player HP by 2 and max boss HP by 3 after room completion.");
		
	//setting monsters act first to true for crew quarters
	crewQuarters->set_m_actFirst (true);
	//setting player additional draw per round to 1 for crew quarters
	crewQuarters->set_m_drawPerR (1);
	//setting player health scale to 3 for crew quarters
	crewQuarters->set_m_pHealthScale (3);
	//setting boss health scale to 2 for crew quarters
	crewQuarters->set_m_bHealthScale (2);
	//setting title for crew quarters
	crewQuarters->set_title("Crew Quarters");
	//setting text for crew quarters
	crewQuarters->set_text("Room Effect: Enemies act first each round.\nBoss Effect: Draw +1 cards each round while fighting the boss.\nIncrease max player HP by 3 and max boss HP by 2 after room completion.");
}