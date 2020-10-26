//including UI.h
#include "UI.h"

//including iostream, string, and stdlib.h
#include <iostream>
#include <string>
#include <stdlib.h>

//using std namespace
using namespace std;

//constructing UI
UI::UI(){

}

//function for setting UI for monster encounters
void UI::SetUI(ActiveMonster& monster) {
	//clearing screen
	system("CLS");
	
	//getting instance of PlayerCardLibrary
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting instance of Player
	Player& user = Player::GetInstance();
	//getting active monster card
	MonsterCard active = monster.get_card();

	//outputting room information
	cout << "Room Title: " << "Medical Bay" << endl;
	cout << "Room Effect: " << "Restore to full HP on completion" << endl;
	cout << "Boss Effect: " << "Boss restores 1 HP per round" << endl;
	cout << endl;
	
	//outputting monster title
	cout << "Monster: " << active.get_title() << endl;
	//outputting monster stats
	cout << "Health: " << active.get_m_health() << " || " << "Strength: " << active.get_strength() << " || " << "Damage Reduction: " << active.get_m_aDR() << endl;
	//outputting last attack used by monster
	cout << "Last Attack Used: " << active.get_m_lastAttack() << endl;
	cout << endl;
	

	cout << "Player Stats" << endl;
	//outputting player stats
	cout << "Health: " << user.get_health() << " || " << "Energy: " << user.get_energy() << " || " << "Strength: " << user.get_strength() << " || " << "Armor: " << user.get_armor() << " || " << "Defense: " << user.get_defense() <<endl;
	//outputting hand size and draw pile size
	cout << "Cards in Hand: " << pLibrary.Hand.size() << " || " << "Cards in Deck: " << pLibrary.DrawPile.size() << endl;
	//outputting discard pile size and exhaust pile size
	cout << "Cards in Discard: " << pLibrary.DiscardPile.size() << " || " << "Cards in Exhaust: " << pLibrary.ExhaustPile.size() << endl;
	cout << endl;

	//outputting cards in player hand
	cout << "Player Hand" << endl;
	//outputting all cards in player hand
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		//telling player the card # and information about the card so they can play it
		cout << "Card " << i + 1 << ": " <<  "(" << pLibrary.Hand[i].get_cost() << ") " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}

void UI::SetBossUI(Boss& alien) {
	//clearing the screen
	system("CLS");

	//getting instance of PlayerCardLibrary
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting instance of Player
	Player& user = Player::GetInstance();
	//getting instance of Boss
	Boss& active = Boss::GetInstance();

	//outputting room information
	cout << "Room Title: " << "Medical Bay" << endl;
	cout << "Room Effect: " << "Restore to full HP on completion" << endl;
	cout << "Boss Effect: " << "Boss restores 1 HP per round" << endl;
	cout << endl;

	//outputting boss information
	cout << "Boss: " << "Alien Commander" << endl;
	//outputting boss stats
	cout << "Health: " << active.get_m_hp() << " || " << "Defense: " << active.get_m_def() << " || " << "Challenge Rating: " << active.get_m_CR() << endl;
	//outputting last attack used by boss
	cout << "Last Attack Used: " << active.get_lastBCard() << endl;
	cout << endl;

	cout << "Player Stats" << endl;
	//outputting player stats
	cout << "Health: " << user.get_health() << " || " << "Energy: " << user.get_energy() << " || " << "Strength: " << user.get_strength() << " || " << "Armor: " << user.get_armor() << " || " << "Defense: " << user.get_defense() << endl;
	//outputting size of player hand and draw pile
	cout << "Cards in Hand: " << pLibrary.Hand.size() << " || " << "Cards in Deck: " << pLibrary.DrawPile.size() << endl;
	//outputting size of discard pile and exhaust pile
	cout << "Cards in Discard: " << pLibrary.DiscardPile.size() << " || " << "Cards in Exhaust: " << pLibrary.ExhaustPile.size() << endl;
	cout << endl;

	//outputting cards in player hand
	cout << "Player Hand" << endl;
	//outputting all cards in player hand
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		//telling player the card # and information about the card so they can play it
		cout << "Card " << i + 1 << ": " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}

//function for displaying upgrade card selection screen
void UI::UpgradeScreen() {
	//clearing screen
	system("CLS");
	//getting instance of PlayerCardLibrary
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//outputting upgrade cards in player hand
	cout << "Choose an Upgrade:" << endl;
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		//telling player the card # and information about the card so they can select one to add to their deck
		cout << "Upgrade Card " << i + 1 << ": " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}
