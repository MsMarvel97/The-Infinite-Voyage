//This class handles player actions
#include <iostream>
#include <string>

#include "Player.h"
using namespace std;
int deckSize = 9;
string deck[9];	

Player::Player()
{
};


void Player::PickACard(std::vector<PlayerCard>& deck) {

	int choice = 0;

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	cout << "Pick a card: ";
	cin >> choice;

	while (cin.fail() || choice < 0 || choice > pLibrary.Hand.size()) {
		cout << "That is not a valid card selection." << endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> choice;
	}
	
	int chosen = choice - 1;
	PlayCard(deck[chosen], chosen);
	
	pLibrary.DiscardPile.emplace_back(deck[chosen]);


	deck.erase(deck.begin() + (chosen));
}

void Player::PlayCard(PlayerCard card, int index) {
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();

		
}



void Player::Initialize(std::vector<PlayerCard>& deck) {

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	Shuffle(pLibrary.UpgradeCards);

	for (int i = 0; i <= 1; i++)
	{
		deck.emplace_back(pLibrary.UpgradeCards[i]);
	}

	Shuffle(deck);

	for (int i = 0; i <= 4; i++)
	{
		DrawCard(deck);
	}

}



void Player::DrawCard(std::vector<PlayerCard>& deck) {

PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//for (int i = 0; i <= 4; i++)
	//{
		if (deck.size() == 0 && pLibrary.DiscardPile.size() > 0)
		{

			int x = pLibrary.DiscardPile.size();

			for (int y = 0; y <= x; y++) {

				deck.emplace_back(pLibrary.DiscardPile[y]);
				pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin() + 0);

			}
			Shuffle(deck);
			DrawCard(deck);
			/*pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin(), pLibrary.DiscardPile.begin() + x);*/
		}
		else if (deck.size() > 0) {
			pLibrary.Hand.emplace_back(deck[0]);
			deck.erase(deck.begin() + 0);
		}


	//}
	//deck.erase(deck.begin(), deck.begin() + 5);
}

void Player::Shuffle(std::vector<PlayerCard> &deck) {
	auto randomizer = std::default_random_engine(std::random_device{}());
	std::shuffle(deck.begin(), deck.end(), randomizer);
}



void Player::ChooseCard(int x, int y)
{
	x = 1;
	y = 0;
	//PlayerCardLibrary::GetInstance().StarterDeck[x];
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	//ActiveMonster::MonsterAction(&pLibrary.PlayerCards[x], &mLibrary.MonsterCards[y]);
}

void Player::Cards()
{
	PlayerCard array[2];
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	
	for (int i = 0; i <= 1; i++)
	{
		array[i] = pLibrary.DrawPile[i];
		std::cout << pLibrary.DrawPile[i].get_title() << "-" << array[i].get_title() << endl;
	}
}