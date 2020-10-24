#ifndef __RoomCardLibrary_H__
#define __RoomCardLibrary_H__
#endif
#include "BossCardLibrary.h"

class RoomCardLibrary {
public:
	RoomCard* medicalBay = new RoomCard;
	RoomCard* crewQuarters = new RoomCard;

private:
	RoomCardLibrary();
};