#ifndef PLAYER_H
#define PLAYER_H
#include "Map/Occupier.hpp"
#include <string>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "ActiveEngimon.hpp"
#include "Skill/Skill.hpp"
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
		void printActiveEngimon();
		void setActiveEngimon(Engimon*);
		void breeding();
		void removeItem();
		void interact();
		bool setEngimon();
		Engimon* getEngimon();
		Engimon* getClosestEnemy();
		ElementType getElement();
		static int validasiInput(std::string pesan, int batasBawah, int batasAtas, int angkalain);

};

#endif