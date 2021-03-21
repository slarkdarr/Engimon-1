#ifndef PLAYER_H
#define PLAYER_H
#include "Map/Occupier.hpp"
#include <string>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "ActiveEngimon.hpp"
#include <vector>


class Player : public Occupier
{
	private:
		vector<Engimon> listengimon;
		ActiveEngimon* activeEngimon;
	public:
		Player(Map&);
		Player(Map&, int x, int y);
		~Player();
		int getLevel();
		bool setPositionOcc(int x, int y);
		void setActiveEngimon(Engimon&);
		ElementType getElement();

};

#endif