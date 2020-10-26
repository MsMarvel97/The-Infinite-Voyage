//defining UI.h
#ifndef __UI_H__
#define __UI_H__
#endif

//including RoomCardLibrary.h
#include "RoomCardLibrary.h"

//class for UI
class UI {
public:
	//function to set UI
	static void SetUI(ActiveMonster& monster);

	//function to set UI for boss encounter
	static void SetBossUI(Boss& alien);

	//function to refresh UI
	static void UpgradeScreen();

private:
	//constructor for UI class
	UI();
};

