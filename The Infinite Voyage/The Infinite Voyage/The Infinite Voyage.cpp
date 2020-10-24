#include <iostream>
using namespace std;
#include "MonsterAction.h"

int main()
{
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	ActiveMonster monster;
	MonsterCard* monsterCard;
	monsterCard = mLibrary.Larva;
	monster = InitMonster(monsterCard);

	cout << monster.activeHealth;


}