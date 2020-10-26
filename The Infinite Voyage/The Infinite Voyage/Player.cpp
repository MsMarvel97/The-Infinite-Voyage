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


void Player::PickACard(std::vector<PlayerCard>& deck, ActiveMonster& monster) {

	Player& user = Player::GetInstance();
	int choice = 0;
	char option;

	cout << "Press E to end round or P to play a card." << endl;
	cin >> option;

	while (option != 'P' && option != 'p'  && option != 'E' && option != 'e') {
		cout << "That is not a valid choice. Please try again." << endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> option;
	}

	if (option == 'P' || option == 'p') {
		PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
		cout << "Pick a card: ";
		cin >> choice;

		while (cin.fail() || choice < 0 || choice > pLibrary.Hand.size()) {
			cout << "That is not a valid card selection. Please try again." << endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}
		int chosen = choice - 1;
		PlayerCard chosenCard = deck[chosen];

		if (chosenCard.get_cost() <= user.get_energy())
		{
			PlayCard(deck[chosen], chosen, monster);
		}

		else
		{
			cout << "You don't have enough energy to play that card." << endl;
			PickACard(deck, monster);
		}


		//pLibrary.DiscardPile.emplace_back(deck[chosen]);

		//deck.erase(deck.begin() + (chosen));
	}

	else {
		EndTurn(deck, monster);
	}

	}




void Player::PlayCard(PlayerCard card, int index, ActiveMonster& monster) {

	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	Player& user = Player::GetInstance();

	user.set_energy(user.get_energy() - card.get_cost());
	user.set_health(user.get_health() + card.get_heal());
	user.set_defense(user.get_defense() + card.get_defense());
	user.set_armor(user.get_armor() + card.get_armor());

	if (card.get_draw() > 0)
	{
		for (int i = 1; i <= card.get_draw(); i++) {
			DrawCard(pLibrary.DrawPile);
		}
	}

	//checking if the card had exhaust
	if (card.get_exhaust() == true) 
	{
		pLibrary.ExhaustPile.emplace_back(card);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + index);
	}
	//dealing damage and checking if monster died
	if (EffectStack::ReceiveDamage((card.get_damage() + user.get_strength()), monster) == true)
	{
		EndRound(pLibrary.DrawPile, monster);
	}
	else 
	{
		pLibrary.DiscardPile.emplace_back(card);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + index);
	}	
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

void Player::NewRound(std::vector<PlayerCard>& deck){
	for (int i = 0; i <= 4; i++) 
		DrawCard(deck);
}


void Player::EndTurn(std::vector<PlayerCard>& deck, ActiveMonster& monster) {
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	Player& user = Player::GetInstance();
	int handSize = pLibrary.Hand.size() - 1;
	int incDmg = EffectStack::MonsterAction(monster);
	int dmgReduction = user.get_armor() + user.get_defense();
	int dmg = incDmg - dmgReduction;
	user.set_energy(3);
	user.set_defense(0);


	if (dmg > 0) {
		user.set_health(user.get_health() - dmg);
	}

	if (user.get_health() <= 0) {
		system("CLS");
		cout << "It's worse than that, you're dead, adventurer!" << endl;
		cout << "GAME OVER" << endl;
		system("pause");
		exit(1);

	}

	for (int i = 0; i <= handSize; i++)
	{
		pLibrary.DiscardPile.emplace_back(pLibrary.Hand[0]);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);

	}
	for (int i = 0; i <= 4; i++) {
		DrawCard(deck);
	}
	
}

void Player::EndRound(std::vector<PlayerCard>& deck, ActiveMonster& monster) {
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	Player& user = Player::GetInstance();
	int handSize = pLibrary.Hand.size() - 1;
	int discardSize = pLibrary.DiscardPile.size() - 1;
	int exhaustSize = pLibrary.ExhaustPile.size() - 1;
	user.set_energy(3);
	user.set_defense(0);
	user.set_strength(0);
	user.set_armor(0);

	for (int i = 0; i <= handSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.Hand[0]);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);
	}

	for (int i = 0; i <= discardSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.DiscardPile[0]);
		pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin() + 0);
	}

	for (int i = 0; i <= exhaustSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.ExhaustPile[0]);
		pLibrary.ExhaustPile.erase(pLibrary.ExhaustPile.begin() + 0);
	}


	user.set_endRound(true);
}


void Player::DrawCard(std::vector<PlayerCard>& deck) {

PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//for (int i = 0; i <= 4; i++)
	//{
		if (pLibrary.DrawPile.size() == 0 && pLibrary.DiscardPile.size() > 0)
		{

			int x = pLibrary.DiscardPile.size() - 1;

			for (int y = 0; y <= x; y++) {
				//refill deck from discard
				pLibrary.DrawPile.emplace_back(pLibrary.DiscardPile[0]);
				pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin() + 0);

			}
			Shuffle(deck);
			DrawCard(deck);
			/*pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin(), pLibrary.DiscardPile.begin() + x);*/
		}
		else if (pLibrary.DrawPile.size() > 0) {
			pLibrary.Hand.emplace_back(pLibrary.DrawPile[0]);
			pLibrary.DrawPile.erase(pLibrary.DrawPile.begin() + 0);
		}


	//}
	//deck.erase(deck.begin(), deck.begin() + 5);
}

void Player::PickRewardCard() {
	Player& user = Player::GetInstance();
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	int choice = 0;
	int handSize = pLibrary.Hand.size() - 1;
		
		cout << "Pick an upgrade card: ";
		cin >> choice;

		while (cin.fail() || choice < 0 || choice > pLibrary.Hand.size()) {
			cout << "That is not a valid card selection. Please try again." << endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		int chosen = choice - 1;
		pLibrary.DrawPile.emplace_back(pLibrary.Hand[chosen]);

		for (int i = 0; i <= handSize; i++)
		{
			pLibrary.DrawPile.emplace_back(pLibrary.Hand[0]);
			pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);
		}

}

void Player::GetRewardCards() {
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	Player::Shuffle(pLibrary.UpgradeCards);
	for (int i = 0; i <= 2; i++) {
		DrawCard(pLibrary.UpgradeCards);
	}
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