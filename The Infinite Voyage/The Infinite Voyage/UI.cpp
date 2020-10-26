#include <iostream>
#include <string>
#include <stdlib.h>
#include "UI.h"
using namespace std;

UI::UI(){

}

void UI::SetUI(ActiveMonster& monster, bool round1) {
	system("CLS");

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	Player& user = Player::GetInstance();
	MonsterCard active = monster.get_card();

	//39 spaces for formatting
	cout << "Room Title: " << "Medical Bay" << endl;
	cout << "Room Effect: " << "Restore to full HP on completion" << endl;
	cout << "Boss Effect: " << "Boss restores 1 HP per round" << endl;
	cout << endl;
	
	cout << "Monster: " << active.get_title() << endl;
	cout << "Health: " << active.get_m_health() << " || " << "Strength: " << active.get_strength() << " || " << "Damage Reduction: " << active.get_m_aDR() << endl;
	if (round1 == false) {
		cout << "Last Attack Used: " << "None." << endl;
	}
	else {
		cout << "Last Attack Used: " << active.get_m_lastAttack() << endl;
	}
	cout << endl;
	
	cout << "Player Stats" << endl;
	cout << "Health: " << user.get_health() << " || " << "Energy: " << user.get_energy() << " || " << "Strength: " << user.get_strength() << " || " << "Armor: " << user.get_armor() << " || " << "Defense: " << user.get_defense() <<endl;
	cout << "Cards in Hand: " << pLibrary.Hand.size() << " || " << "Cards in Deck: " << pLibrary.DrawPile.size() << endl;
	cout << "Cards in Discard: " << pLibrary.DiscardPile.size() << " || " << "Cards in Exhaust: " << pLibrary.ExhaustPile.size() << endl;
	cout << endl;


	cout << "Player Hand" << endl;
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		cout << "Card " << i + 1 << ": " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}

void UI::UpgradeScreen() {
	system("CLS");

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	cout << "Choose an Upgrade:" << endl;
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		cout << "Upgrade Card " << i + 1 << ": " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}
