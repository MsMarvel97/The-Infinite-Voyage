#include <iostream>
#include <string>
#include "UI.h"
using namespace std;

UI::UI(){

}

void UI::SetUI() {

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//39 spaces for formatting
	cout << "Room Title: " << "Medical Bay" << endl;
	cout << "Room Effect: " << "Restore to full HP on completion" << endl;
	cout << "Boss Effect: " << "Boss restores 1 HP per round" << endl;
	cout << endl;
	
	cout << "Monster: " << "Larva" << endl;
	cout << "Health: " << "6" << " || " << "Strength: " << "0" << endl;
	cout << "Last Attack Used: " << "Berserk" << " - deal 2 damage" << endl;
	cout << endl;
	
	cout << "Player Stats" << endl;
	cout << "Health: " << "30" << " || " << "Energy: " << "3" << " || " << "Strength: " << "0" << " || " << "Armor: " << "0" << endl;
	cout << "Cards in Hand: " << "5" << " || " << "Cards in Deck: " << "5" << " || " << "Cards in Discard: " << "0" << endl;
	cout << endl;


	cout << "Player Hand" << endl;
	for (int i = 0; i <= pLibrary.Hand.size() - 1; i++)
	{
		cout << "Card " << i + 1 << ": " << pLibrary.Hand[i].get_title() << " - " << pLibrary.Hand[i].get_text() << endl;
	}
	cout << endl;
}

void UI::RefreshUI() {

}
