#pragma once
#ifndef __CardTemplate_H__
#define __CardTemplate_H__
#endif

#include <iostream>
#include <string>


class Card {
public:
	int m_damage, m_defense, m_armor, m_strength, m_heal;
	std::string m_text;
	std::string m_title;

	int get_damage() { return m_damage; }
	void set_damage(int dmg) { m_damage = dmg; }

	int get_defense() { return m_defense; }
	void set_defense(int defense) { m_defense = defense; }

	int get_armor() { return m_armor; }
	void set_armor(int armor) { m_armor = armor; }

	int get_strength() { return m_strength; }
	void set_strength(int strength) { m_strength = strength; }

	int get_heal() { return m_heal; }
	void set_heal(int heal) { m_heal = heal; }

	std::string get_text() { return m_text; }
	void set_text(std::string text) { m_text = text; }

	std::string get_title() { return m_title; }
	void set_title(std::string title) { m_title = title; }

};


class PlayerCard : public Card {
public:
	int m_cost, m_draw, m_maxHP, m_energy;
	bool m_exhaust;
	std::string m_type;

	int get_cost() { return m_cost; }
	void set_cost(int cost) { m_cost = cost; }

	int get_draw() { return m_draw; }
	void set_draw(int draw) { m_draw = draw; }

	int get_maxHP() { return m_maxHP; }
	void set_maxHP(int maxHP) { m_maxHP = maxHP; }

	int get_energy() { return m_energy; }
	void set_energy(int energy) { m_energy = energy; }

	bool get_exhaust() { return m_exhaust; }
	void set_exhaust(bool exhaust) { m_exhaust = exhaust; }

	std::string get_type() { return m_type; }
	void set_type(const std::string& type) { m_type = type; }






	/*public PlayerCard(int damage, int defense, int armor, int strength, heal, text, title, cost, draw, maxHP, energy, exhaust, type)
	{

	}*/
};

class MonsterCard : public Card {
public:
	int m_health, m_selfDmg;
	int m_damage2, m_heal2, m_rollChance, m_reduceDmg, m_selfDmg2;
	char m_aChoice[1];

	int get_m_selfDmg() { return m_selfDmg; }
	void set_m_selfDmg(int sDmg) { m_selfDmg = sDmg; }

	int get_m_health() { return m_health; }
	void set_m_health(int health) { m_health = health; }

};

class BossCard : public Card {
public:
	int CR;
};

class RoomCard : public Card {
public:
	int m_pHealthScale, m_bHealthScale, m_dmgPerR, m_pStrBuff, m_monsterStrBuff, m_bHPR;
	int m_drawPerR; //# of extra cards the player draws per round
	bool m_actFirst;
	bool m_restoreHP; //restores player to full hp if true

	int get_m_pHealthScale() { return m_pHealthScale; }
	void set_m_pHealthScale(int pHS) { m_pHealthScale = pHS; }

	int get_m_bHealthScale() { return m_bHealthScale; }
	void set_m_bHealthScale(int bHS) { m_bHealthScale = bHS; }

	int get_m_dmgPerR() { return m_dmgPerR; }
	void set_m_dmgPerR(int dPR) { m_dmgPerR = dPR; }

	int get_m_drawPerR() { return m_drawPerR; }
	void set_m_drawPerR(int drawPR) { m_drawPerR = drawPR; }

	int get_m_pStrBuff() { return m_pStrBuff; }
	void set_m_pStrBuff(int pSB) { m_pStrBuff = pSB; }

	int get_m_monsterStrBuff() { return m_monsterStrBuff; }
	void set_m_monsterStrBuff(int mSB) { m_monsterStrBuff = mSB; }

	int get_m_bHPR() { return m_bHPR; }
	void set_m_bHPR(int bHPR) { m_bHPR = bHPR; }

	bool get_m_actFirst() { return m_actFirst; }
	void set_m_actFirst(bool aF) { m_actFirst = aF; }

	bool get_m_restoreHP() { return m_restoreHP; }
	void set_m_restoreHP(bool rHP) { m_restoreHP = rHP; }

};