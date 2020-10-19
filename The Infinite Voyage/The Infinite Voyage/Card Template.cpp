#include <iostream>
#include <string>
using namespace std;

class Card {

public:
	int attack, defense, armor, strength, heal;
};

class PlayerCard : public Card {
public:
	int cost, draw, maxHP, energy;
	bool exhaust;
};

class MonsterCard : public Card {
	int health;
	char aChoice[];
};

class BossCard : public Card {
	int CR;
	

};

class RoomCard : public Card {
	int pHealthScale, bHealthScale, dmgPerR, drawPerR, pStrBuff, mStrBuff, bHPR;
	bool actFirst;
};