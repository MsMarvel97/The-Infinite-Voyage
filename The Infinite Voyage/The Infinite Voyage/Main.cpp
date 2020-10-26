//including Main.h
#include "Main.h"
//including iostream
#include <iostream>
//using std namespace
using namespace std;

//main function
int main()
{
	//getting an instance of the PlayerCardLibrary
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting an instance of the MonsterCardLibrary
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();

	//shuffling the monster deck
	MonsterCardLibrary::MonsterShuffle(mLibrary.MonsterDeck);
	//creating an active monster that is a copy of the top card of the monster deck so values can be changed without affecting
	//the original card
	ActiveMonster monster(mLibrary.MonsterDeck[0]);
	
	//getting an instance of the Player class
	Player& user = Player::GetInstance();
	//calling the initialize function and sending it the draw pile
	Player::Initialize(pLibrary.DrawPile);

	
	//core gameplay loop which will execute until the endRound bool has been set to true
	while (user.get_endRound () == false) {
		//setting the UI with the active monster
		UI::SetUI(monster);
		//starting the sequence for player actions
		Player::PickACard(pLibrary.Hand, monster);
	}

	//removing the top card from the monster deck
	mLibrary.MonsterDeck.erase(mLibrary.MonsterDeck.begin() + 0);
	//setting the endRound bool back to false
	user.endRound = false;

	//geting reward cards for player to select from
	Player::GetRewardCards();
	//displaying reward card options
	UI::UpgradeScreen();
	//letting player pick a card to add to their deck
	Player::PickRewardCard();

	//redrawing player hand
	Player::NewRound(pLibrary.DrawPile);
	//setting a new active monster
	ActiveMonster monster2(mLibrary.MonsterDeck[0]);

	//restarting the core gameplay loop to execute until endRound is set to true
	while (user.get_endRound() == false) {
		UI::SetUI(monster2);
		Player::PickACard(pLibrary.Hand, monster2);
	}

	//getting rewrad cards for player to select from
	Player::GetRewardCards();
	//displaying reward card options
	UI::UpgradeScreen();
	//letting player pick a card to add to their deck
	Player::PickRewardCard();

	//This was meant to be the section for the boss encounter, but time constraints prevented its inclusion

	//Player::NewRound(pLibrary.DrawPile);
	//Boss& alienCommander = Boss::GetInstance();

	//while (user.get_endRound() == false) {
	//	UI::SetBossUI(alienCommander);
	//	Player::PickACard(pLibrary.Hand, alienCommander);
	//}

	//clearing the screen
	system("CLS");
	//end of game messages for player
	cout << "Congratulations! The boss awaits." << endl;
	cout << "You have completed the demo for 'The Infinite Voyage'." << endl;
	cout << "Thanks for playing!" << endl;

	//END\\

}

