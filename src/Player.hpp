#ifndef PLAYER_H
#define PLAYER_H
#include "Map/Occupier.hpp"
#include <string>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "ActiveEngimon.hpp"
#include "Species/Skill.hpp"
#include "Inventory.hpp"
#include "Enemy.hpp"
#include <vector>


class Player : public Occupier
{
	private:
		ActiveEngimon* activeEngimon;
	public:
		Inventory<Skill, Engimon> *inventory;

		Player(Map&);
		Player(Map&, int x, int y);
		~Player();
		int getLevel();
		bool setPositionOcc(int x, int y);
		void setActiveEngimon(Engimon&);
		Engimon* getEngimon();

		Engimon* getClosestEnemy();
		ElementType getElement();

};

#endif