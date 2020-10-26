#include <iostream>
using namespace std;
#include "Main.h"

int main()
{
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	MonsterCardLibrary::MonsterShuffle(mLibrary.MonsterDeck);
	Player& user = Player::GetInstance();

	ActiveMonster monster(mLibrary.MonsterDeck[0]);
	Player::Initialize(pLibrary.DrawPile);

	//round
	while (user.get_endRound () == false) {
		UI::SetUI(monster, true);
		Player::PickACard(pLibrary.Hand, monster);
	}

	mLibrary.MonsterDeck.erase(mLibrary.MonsterDeck.begin() + 0);
	user.endRound = false;

	Player::GetRewardCards();
	UI::UpgradeScreen();
	Player::PickRewardCard();

	Player::NewRound(pLibrary.DrawPile);
	ActiveMonster monster2(mLibrary.MonsterDeck[0]);

	while (user.get_endRound() == false) {
		UI::SetUI(monster2, true);
		Player::PickACard(pLibrary.Hand, monster2);
	}
	system("CLS");
	cout << "Congratulations! The boss awaits." << endl;
	cout << "You have completed the demo for 'The Infinite Voyage'." << endl;
	cout << "Thanks for playing!" << endl;

}


//MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
//ActiveMonster monster;
//MonsterCard* monsterCard;
//monsterCard = mLibrary.Larva;
//monster = InitMonster(monsterCard);

//cout << monster.activeHealth;
