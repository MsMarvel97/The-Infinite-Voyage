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