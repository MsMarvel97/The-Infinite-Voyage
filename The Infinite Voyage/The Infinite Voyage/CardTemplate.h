#pragma once
#ifndef __CardTemplate_H__
#define __CardTemplate_H__
#endif
#include <iostream>
#include <string>

//basic card template
class Card {
public:
	//setting vars for values that can appear on any card: damage, defense, armor, strength, heal, text, and title
	int m_damage = 0, m_defense = 0, m_armor = 0, m_strength = 0, m_heal = 0;
	std::string m_text;
	std::string m_title;

	//getter and setter for damage
	int get_damage() { return m_damage; }
	void set_damage(int dmg) { m_damage = dmg; }

	//getter and setter for defense
	int get_defense() { return m_defense; }
	void set_defense(int defense) { m_defense = defense; }

	//getter and setter for armor
	int get_armor() { return m_armor; }
	void set_armor(int armor) { m_armor = armor; }

	//getter and setter for strength
	int get_strength() { return m_strength; }
	void set_strength(int strength) { m_strength = strength; }

	//getter and setter for heal
	int get_heal() { return m_heal; }
	void set_heal(int heal) { m_heal = heal; }

	//getter and setter for text
	std::string get_text() { return m_text; }
	void set_text(std::string text) { m_text = text; }

	//getter and setter for title
	std::string get_title() { return m_title; }
	void set_title(std::string title) { m_title = title; }

};


class PlayerCard : public Card {
public:
	int m_cost = 0, m_draw = 0, m_maxHP = 0, m_energy = 0;
	bool m_exhaust = false;
	std::string m_type;

	//getter and setter for cost
	int get_cost() { return m_cost; }
	void set_cost(int cost) { m_cost = cost; }

	//getter and setter for draw value
	int get_draw() { return m_draw; }
	void set_draw(int draw) { m_draw = draw; }

	//getter and setter for maxHP increase
	int get_maxHP() { return m_maxHP; }
	void set_maxHP(int maxHP) { m_maxHP = maxHP; }

	//getter and setter for energy increase
	int get_energy() { return m_energy; }
	void set_energy(int energy) { m_energy = energy; }

	//getter and setter for exhaust state
	bool get_exhaust() { return m_exhaust; }
	void set_exhaust(bool exhaust) { m_exhaust = exhaust; }

	//getter and setter for card type
	std::string get_type() { return m_type; }
	void set_type(const std::string& type) { m_type = type; }
};

class MonsterCard : public Card {
public:
	int m_health = 0, m_A1selfDmg = 0, m_A2selfDmg = 0, m_A1reduceDmg = 0, m_A2reduceDmg = 0, m_rollChance = 0, m_A2damage = 0, m_A2defense = 0, m_A1strength = 0, m_A2strength = 0, m_A2heal = 0, m_aDR = 0;
	std::string m_a1Text ;
	std::string m_a2Text;
	std::string m_lastAttack = ("None.");

	//getter and setter for ability 1 text
	std::string get_m_a1Text() { return m_a1Text; }
	void set_m_a1Text(const std::string& a1) { m_a1Text = a1; }

	//getter and setter for ability 2 text
	std::string get_m_a2Text() { return m_a2Text; }
	void set_m_a2Text(const std::string& a2) { m_a2Text = a2; }

	//getter and setter for text related to last attack
	std::string get_m_lastAttack() { return m_lastAttack; }
	void set_m_lastAttack (const std::string& la) { m_lastAttack = la; }

	//getter and setter for self damage on ability 1
	int get_m_A1selfDmg() { return m_A1selfDmg; }
	void set_m_A1selfDmg(int sDmg) { m_A1selfDmg = sDmg; }

	//getter and setter for self damage on ability 2
	int get_m_A2selfDmg() { return m_A2selfDmg; }
	void set_m_A2selfDmg(int sDmg) { m_A2selfDmg = sDmg; }

	//getter and setter for monster health
	int get_m_health() { return m_health; }
	void set_m_health(int health) { m_health = health; }

	//getter and setter for roll chance
	int get_m_rollChance() { return m_rollChance; }
	void set_m_rollChance(int chance) { m_rollChance = chance; }

	//getter and setter for damage reduction on ability 1
	int get_m_A1reduceDmg() { return m_A1reduceDmg; }
	void set_m_A1reduceDmg(int reduceDmg) { m_A1reduceDmg = reduceDmg; }

	//getter and setter for damage reduction on ability 2
	int get_m_A2reduceDmg() { return m_A2reduceDmg; }
	void set_m_A2reduceDmg(int reduceDmg) { m_A2reduceDmg = reduceDmg; }

	//getter and setter for strength on ability 1
	int get_m_A1strength() { return m_A1strength; }
	void set_m_A1strength(int str) { m_A1strength = str; }

	//getter and setter for strength on ability 2
	int get_m_A2strength() { return m_A2strength; }
	void set_m_A2strength(int str) { m_A2strength = str; }

	//getter and setter for damage on ability 2
	int get_m_A2damage() { return m_A2damage; }
	void set_m_A2damage(int damage) { m_A2damage = damage; }

	//getter and setter for heal on ability 2
	int get_m_A2heal() {return m_A2heal;}
	void set_m_A2heal(int healing) { m_A2heal = healing; }

	//getter and setter for active damage reduction
	int get_m_aDR() { return m_aDR; }
	void set_m_aDR(int damageReduction) { m_aDR = damageReduction; }
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

	//getter and setter for player health scaling
	int get_m_pHealthScale() { return m_pHealthScale; }
	void set_m_pHealthScale(int pHS) { m_pHealthScale = pHS; }

	//getter and setter for boss health scaling
	int get_m_bHealthScale() { return m_bHealthScale; }
	void set_m_bHealthScale(int bHS) { m_bHealthScale = bHS; }

	//getter and setter for damage per round room effect
	int get_m_dmgPerR() { return m_dmgPerR; }
	void set_m_dmgPerR(int dPR) { m_dmgPerR = dPR; }

	//getter and setter for draw per round room effect
	int get_m_drawPerR() { return m_drawPerR; }
	void set_m_drawPerR(int drawPR) { m_drawPerR = drawPR; }

	//getter and setter for player strength buff room effect
	int get_m_pStrBuff() { return m_pStrBuff; }
	void set_m_pStrBuff(int pSB) { m_pStrBuff = pSB; }

	//getter and setter for monster strength buff room effect
	int get_m_monsterStrBuff() { return m_monsterStrBuff; }
	void set_m_monsterStrBuff(int mSB) { m_monsterStrBuff = mSB; }

	//getter and setter for boss heal per round boss effect
	int get_m_bHPR() { return m_bHPR; }
	void set_m_bHPR(int bHPR) { m_bHPR = bHPR; }

	//getter and setter for monsters acting first room effect 
	bool get_m_actFirst() { return m_actFirst; }
	void set_m_actFirst(bool aF) { m_actFirst = aF; }

	//getter and setter for full player HP restoration room effect
	bool get_m_restoreHP() { return m_restoreHP; }
	void set_m_restoreHP(bool rHP) { m_restoreHP = rHP; }

};