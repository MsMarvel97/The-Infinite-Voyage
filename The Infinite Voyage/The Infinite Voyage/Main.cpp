#include <iostream>
using namespace std;
#include "Main.h"

int main()
{
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	Player::Initialize(pLibrary.DrawPile);
	
	UI::SetUI();
	
	Player::PickACard(pLibrary.Hand);

}


//MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
//ActiveMonster monster;
//MonsterCard* monsterCard;
//monsterCard = mLibrary.Larva;
//monster = InitMonster(monsterCard);

//cout << monster.activeHealth;
