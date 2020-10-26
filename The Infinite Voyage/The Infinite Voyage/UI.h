#ifndef __UI_H__
#define __UI_H__
#endif
#include "RoomCardLibrary.h"

//class for UI
class UI {
public:
	//function to set UI
	static void SetUI(ActiveMonster& monster, bool round1);

	static void SetBossUI(Boss& alien);

	//function to refresh UI
	static void UpgradeScreen();

private:
	//constructor for UI class
	UI();
};

