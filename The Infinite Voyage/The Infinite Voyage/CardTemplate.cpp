#include <iostream>
#include <string>
using namespace std;

class Card {
public:
	int damage, defense, armor, strength, heal;
	string text;
	string title;
};

class PlayerCard : public Card {
public:
	int cost, draw, maxHP, energy;
	bool exhaust;
};

class MonsterCard : public Card {
public:
	int health;
	char aChoice[];

};

class BossCard : public Card {
public:
	int CR;
};

class RoomCard : public Card {
public:
	int pHealthScale, bHealthScale, dmgPerR, drawPerR, pStrBuff, mStrBuff, bHPR;
	bool actFirst;

};