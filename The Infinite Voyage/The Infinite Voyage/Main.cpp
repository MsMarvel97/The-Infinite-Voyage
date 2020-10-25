#include <iostream>
using namespace std;
#include "Main.h"

int main()
{
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	ActiveMonster monster(mLibrary.Larva);

	Player::Initialize(pLibrary.DrawPile);

	monster.get_card().set_damage(5);
	
	UI::SetUI();
	
	Player::PickACard(pLibrary.Hand);
}


//MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
//ActiveMonster monster;
//MonsterCard* monsterCard;
//monsterCard = mLibrary.Larva;
//monster = InitMonster(monsterCard);

//cout << monster.activeHealth;
