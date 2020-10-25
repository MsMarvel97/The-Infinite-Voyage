#ifndef __Player_H__
#define __Player_H__
#endif
#include "MonsterAction.h"

class Player {
public:
	static void Shuffle (std::vector<PlayerCard> &deck);
	static void ChooseCard(int x, int y);
	static void PickACard(std::vector<PlayerCard>& deck);
	static void Cards();
	static void DrawCard(std::vector<PlayerCard>& deck);
	static void PlayCard(PlayerCard);
	static void Initialize(std::vector<PlayerCard> &deck);

	
private:
	Player();
};