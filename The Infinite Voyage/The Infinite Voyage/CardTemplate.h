#ifndef __CardTemplate_H__
#define __CardTemplate_H__
#endif

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
	string type;
};

class MonsterCard : public Card {
public:
	int health;
	bool attackOne, attackTwo;
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
	void RoomEffect() {

	}
	void BossEffect() {

	}
};