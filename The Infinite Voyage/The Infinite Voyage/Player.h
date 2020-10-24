#ifndef __Player_H__
#define __Player_H__
#endif
#include "MonsterAction.h"

class Player {
public:
	static Player& GetInstance()
	{
		static Player Instance = Player();
		return Instance;
	}
	static void ChooseCard(int x, int y);
	static void Cards();
private:
	Player();
};