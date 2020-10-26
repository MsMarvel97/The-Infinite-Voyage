//This class handles player actions

//including Player.h
#include "Player.h"

//including iostream and string for later functions
#include <iostream>
#include <string>

//using std namespace
using namespace std;

//constructing player class
Player::Player()
{
};


//function to handle the player picking a card
void Player::PickACard(std::vector<PlayerCard>& deck, ActiveMonster& monster) {

	//getting an instance of the player and storing it in a var to simplify syntax
	Player& user = Player::GetInstance();
	//int to hold player card choice
	int choice = 0;
	//char to hold menu option
	char option;

	//requesting player end the round of play the card
	cout << "Press E to end round or P to play a card." << endl;
	cin >> option;

	//requesting player provide input again if value of option does not match a P or E
	while (option != 'P' && option != 'p'  && option != 'E' && option != 'e') {
		cout << "That is not a valid choice. Please try again." << endl;
		std::cin.clear();
		std::cin.ignore(256, '\n');
		std::cin >> option;
	}

	//starting the sequence for picking a card if value of option matches a P
	if (option == 'P' || option == 'p') {
		PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

		//requesting player pick a card from their hand to play
		cout << "Pick a card (enter the # of the card): ";
		cin >> choice;

		//checking if value of choice matches a value in the player hand and requesting player try again if it doesn't
		while (cin.fail() || choice < 0 || choice > pLibrary.Hand.size()) {
			cout << "That is not a valid card selection. Please try again." << endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		//setting chosen card to choice - 1 to match up with index values of player hand
		int chosen = choice - 1;
		//setting chosen card to card chosen from hand
		PlayerCard chosenCard = deck[chosen];

		//checking if player hs enough energy to play the card
		if (chosenCard.get_cost() <= user.get_energy())
		{
			//if player has enough energy, calling the PlayCard function and passing it the chosen card, chosen card index, and active monster
			PlayCard(deck[chosen], chosen, monster);
		}

		//requesting player choose again if they do not have enough energy
		else
		{
			cout << "You don't have enough energy to play that card." << endl;
			PickACard(deck, monster);
		}


	}

	else {
		//calling EndTurn function and passing it player hand and active monster after card is played
		EndTurn(deck, monster);
	}

	}



//function for playing a card
void Player::PlayCard(PlayerCard card, int index, ActiveMonster& monster) {

	//getting instance of player library and storing it in a variable
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting instance of monster library and storing it in a variable
	MonsterCardLibrary& mLibrary = MonsterCardLibrary::GetInstance();
	Player& user = Player::GetInstance();

	//changing player stats by the values on the cards being played\\

	user.set_energy(user.get_energy() + (card.get_energy() - card.get_cost()));
	user.set_health(user.get_health() + card.get_heal());
	user.set_defense(user.get_defense() + card.get_defense());
	user.set_armor(user.get_armor() + card.get_armor());


	//checking if played card will cause player to draw cards
	if (card.get_draw() > 0)
	{
		//drawing cards equal to the value of draw
		for (int i = 1; i <= card.get_draw(); i++) {
			DrawCard(pLibrary.DrawPile);
		}
	}


	//checking if the card had exhaust and placing it in the exhaust pile if true
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


	//discarding player card
	else if (card.get_exhaust() == false)
	{
		//adding cards in hand to discard
		pLibrary.DiscardPile.emplace_back(card);
		//removing cards from hand
		pLibrary.Hand.erase(pLibrary.Hand.begin() + index);
	}	
}


//function to initialize player deck at the start of the game
void Player::Initialize(std::vector<PlayerCard>& deck) {

	//getting instance of player library
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//sending the UpgradeCards deck to the shuffle function
	Shuffle(pLibrary.UpgradeCards);

	//putting the top 2 cards of the UpgradeCards deck into the player deck
	for (int i = 0; i <= 1; i++)
	{
		deck.emplace_back(pLibrary.UpgradeCards[i]);
	}

	//shuffling the player deck
	Shuffle(deck);

	//drawing 5 cards from the player deck
	for (int i = 0; i <= 4; i++)
	{
		DrawCard(deck);
	}

}

//function to draw a new hand at the start of a round
void Player::NewRound(std::vector<PlayerCard>& deck){
	for (int i = 0; i <= 4; i++) 
		DrawCard(deck);
}


//function to handle the end of a turn
void Player::EndTurn(std::vector<PlayerCard>& deck, ActiveMonster& monster) {

	//getting an instance of the player library
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting an instance of the player
	Player& user = Player::GetInstance();

	//setting integer to hold player hand size
	int handSize = pLibrary.Hand.size() - 1;
	//setting integer to hold the damage the player will receive from the monster action
	int incDmg = EffectStack::MonsterAction(monster);
	//setting integer to hold the total damage reduction the player has
	int dmgReduction = user.get_armor() + user.get_defense();
	//setting integer to hold the final damage that will be dealt to the player
	int dmg = incDmg - dmgReduction;

	//resetting player energy and defense values
	user.set_energy(3);
	user.set_defense(0);

	//if damage value is greater than 0, reducing player health by that amount
	if (dmg > 0) {
		user.set_health(user.get_health() - dmg);
	}

	//checking if player is dead and ending the game if they are
	if (user.get_health() <= 0) {
		system("CLS");
		cout << "It's worse than that, you're dead, adventurer!" << endl;
		cout << "GAME OVER" << endl;
		system("pause");
		exit(1);

	}

	//discarding any cards left in player hand
	for (int i = 0; i <= handSize; i++)
	{
		pLibrary.DiscardPile.emplace_back(pLibrary.Hand[0]);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);

	}
	//drawing a new hand
	NewRound(deck);

	
}

//function to handle the cleanup after the monster is defeated.
void Player::EndRound(std::vector<PlayerCard>& deck, ActiveMonster& monster) {
	//getting an instance of the player library
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//getting instance of player
	Player& user = Player::GetInstance();
	//integer to hold player hand size
	int handSize = pLibrary.Hand.size() - 1;
	//integer to hold size of discard pile
	int discardSize = pLibrary.DiscardPile.size() - 1;
	//integer to hold size of exhaust pile
	int exhaustSize = pLibrary.ExhaustPile.size() - 1;

	//resetting player stats
	user.set_energy(3);
	user.set_defense(0);
	user.set_strength(0);
	user.set_armor(0);

	//emptying the player hand into the draw pile
	for (int i = 0; i <= handSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.Hand[0]);
		pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);
	}

	//emptying the discard pile into the draw pile
	for (int i = 0; i <= discardSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.DiscardPile[0]);
		pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin() + 0);
	}

	//emptying the exhaust pile into the draw pile
	for (int i = 0; i <= exhaustSize; i++)
	{
		pLibrary.DrawPile.emplace_back(pLibrary.ExhaustPile[0]);
		pLibrary.ExhaustPile.erase(pLibrary.ExhaustPile.begin() + 0);
	}

	//setting endRound to true so main.cpp will move to the next step
	user.set_endRound(true);
}


//function to handle drawing a card
void Player::DrawCard(std::vector<PlayerCard>& deck) {

//getting instance of player card library
PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

		//checking if draw pile is empty and discard pile still has cards in it
		if (pLibrary.DrawPile.size() == 0 && pLibrary.DiscardPile.size() > 0)
		{
			//setting an int for the size of the discard pile
			int x = pLibrary.DiscardPile.size() - 1;

			//putting the contents of the discard pile into the draw pile
			for (int y = 0; y <= x; y++) {
				//refill deck from discard
				pLibrary.DrawPile.emplace_back(pLibrary.DiscardPile[0]);
				pLibrary.DiscardPile.erase(pLibrary.DiscardPile.begin() + 0);

			}
			//shuffling the player draw pile
			Shuffle(pLibrary.DrawPile);
			//calling the DrawCard function again
			DrawCard(pLibrary.DrawPile);
		}
		//checking if there are still cards to draw
		else if (pLibrary.DrawPile.size() > 0) {
			//adding the top card of the draw pile to the player hand
			pLibrary.Hand.emplace_back(pLibrary.DrawPile[0]);
			//removing the top card of the draw pile from the draw pile
			pLibrary.DrawPile.erase(pLibrary.DrawPile.begin() + 0);
		}

}

//function to handle picking a reward card
void Player::PickRewardCard() {
	//getting an instance of the player
	Player& user = Player::GetInstance();
	//getting an instance of the player library
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();

	//setting an int to hold the player card choice
	int choice = 0;
	//integer to hold the player hand size
	int handSize = pLibrary.Hand.size() - 1;
		
		//requesting the player pick an upgrade card
		cout << "Pick an upgrade card: ";
		cin >> choice;

		//checking if value entered is both an integer and within the range of cards in the player hand
		while (cin.fail() || choice < 0 || choice > pLibrary.Hand.size()) {
			cout << "That is not a valid card selection. Please try again." << endl;
			std::cin.clear();
			std::cin.ignore(256, '\n');
			std::cin >> choice;
		}

		//integer to hold index value of chosen card
		int chosen = choice - 1;
		//adding the chosen card to the player draw pile
		pLibrary.DrawPile.emplace_back(pLibrary.Hand[chosen]);

		//erasing the cards in the player hand
		for (int i = 0; i <= handSize; i++)
		{
			pLibrary.Hand.erase(pLibrary.Hand.begin() + 0);
		}
}

//function to get reward cards to be selected from
void Player::GetRewardCards() {
	//getting an instance of player library
	PlayerCardLibrary& pLibrary = PlayerCardLibrary::GetInstance();
	//shuffling the UpgradeCards deck
	Player::Shuffle(pLibrary.UpgradeCards);

	//drawing the top 3 cards from the upgrade deck
	for (int i = 0; i <= 2; i++) {
		pLibrary.Hand.emplace_back(pLibrary.UpgradeCards[i]);
	}
}

//function to shuffle a deck of player cards
void Player::Shuffle(std::vector<PlayerCard> &deck) {
	//variable to hold a random seed for the shuffle
	auto randomizer = std::default_random_engine(std::random_device{}());
	//shuffling the deck with the random seed that has been generated
	std::shuffle(deck.begin(), deck.end(), randomizer);
}

