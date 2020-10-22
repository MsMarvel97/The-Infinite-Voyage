#pragma once
#ifndef __CardTemplate_H__
#define __CardTemplate_H__
#endif

#include <iostream>
#include <string>
using namespace std;

class Card {
public:
	int damage = 0, defense = 0, armor = 0, strength = 0, heal = 0;
	string text = "";
	string title = "";

	int get_damage() { return damage; }
	void set_damage(int damage) { damage = damage; }

	int get_defense() { return defense; }
	void set_defense(int defense) { defense = defense; }

	int get_armor() { return armor; }
	void set_armor(int armor) { armor = armor; }

	int get_strength() { return strength; }
	void set_strength(int strength) { strength = strength; }

	int get_heal() { return heal; }
	void set_heal(int heal) { heal = heal; }

	string get_text() { return text; }
	void set_text(string text) { text = text; }

	string get_title() { return title; }
	void set_title(string title) { title = title; }

};


class PlayerCard : public Card {
public:
	int cost = 0, draw = 0, maxHP = 0, energy = 0;
	bool exhaust = false;
	string type = "";

	int get_cost() { return cost; }
	void set_cost(int cost) { cost = cost; }

	int get_draw() { return draw; }
	void set_draw(int draw) { draw = draw; }

	int get_maxHP() { return maxHP; }
	void set_maxHP(int maxHP) { maxHP = maxHP; }

	int get_energy() { return energy; }
	void set_energy(int energy) { energy = energy; }

	bool get_exhaust() { return exhaust; }
	void set_exhaust(int exhaust) { exhaust = exhaust; }

	string get_type() { return type; }
	void set_type(string type) { type = type; }






	/*public PlayerCard(int damage, int defense, int armor, int strength, heal, text, title, cost, draw, maxHP, energy, exhaust, type)
	{

	}*/
};

class MonsterCard : public Card {
public:
	int health = 0;
	bool attackOne = false, attackTwo = false;
	char aChoice[1];

	int get_health() { return health; }
	void set_title(int health) { health = health; }
};

class BossCard : public Card {
public:
	int CR;
};

class RoomCard : public Card {
public:
	int pHealthScale = 0, bHealthScale = 0, dmgPerR = 0, drawPerR = 0, pStrBuff = 0, mStrBuff = 0, bHPR = 0;
	bool actFirst = false;
};