//This class handles player actions
#include <iostream>
#include <string>
#include "Player.h"
using namespace std;
int deckSize = 9;
string deck[9];	

class Player
{

	static void CurrentHand()
	{
		cout << "Hello";

	}

	static void Deck()
	{



	}
	void ChooseCard(int x, int y)
	{
		x = 1;
		y = 0;
		PlayerCardLibrary::GetInstance().PlayerCards[x];
		PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
		MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
		ActiveMonster::MonsterAction(&pLibrary.PlayerCards[x], &mLibrary.MonsterCards[y]);
	}
};