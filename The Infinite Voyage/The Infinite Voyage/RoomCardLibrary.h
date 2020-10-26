//defining RoomCardLibrary.h
#ifndef __RoomCardLibrary_H__
#define __RoomCardLibrary_H__
#endif

//including BossCardLibrary.h
#include "BossCardLibrary.h"

//declaring RoomCardLibrary class
class RoomCardLibrary {
public:
	//declaring rooms\\
	//declaring medical bay
	RoomCard* medicalBay = new RoomCard;
	//declaring crew quarters
	RoomCard* crewQuarters = new RoomCard;

private:
	//constructor for RoomCardLibrary
	RoomCardLibrary();
};