#ifndef __RoomCardLibrary_H__
#define __RoomCardLibrary_H__
#endif
#include "CardTemplate.h"
#include "MasterCardLibrary.h"

class RoomCardLibrary {
public:
	RoomCard* medicalBay;
	RoomCard* crewQuarters;

	static RoomCardLibrary& GetInstance()
	{
		static RoomCardLibrary Instance = RoomCardLibrary();
		return Instance;
	}

private:

	RoomCardLibrary();

};
