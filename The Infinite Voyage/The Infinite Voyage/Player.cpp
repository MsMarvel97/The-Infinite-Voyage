//This class handles player actions
#include <iostream>
#include <string>
#include "PlayerCardLibrary.h"
using namespace std;
int deckSize = 9;
string deck[9];	

Player::Player()
{};

	//void CurrentHand()
	//{
	//	cout << "Hello";

	//}

	//static void Deck()
	//{



	//}
void Player::ChooseCard(int x, int y)
{

	x = 1;
	y = 0;
	PlayerCardLibrary::GetInstance().PlayerCards[x];
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	//ActiveMonster::MonsterAction(&pLibrary.PlayerCards[x], &mLibrary.MonsterCards[y]);
}

void Player::Cards()
	{
		for (int i = 0; i <= 1; i++)
		{
			PlayerCard array[2];
			PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
			PlayerCard* playerCard;

			playerCard = pLibrary.attack;

			array[i] = pLibrary.PlayerCards[i];
			std::cout << pLibrary.PlayerCards[i].get_title() << "-" << array[i].get_title() << endl;			
		}
	}
