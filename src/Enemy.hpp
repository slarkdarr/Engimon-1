#ifndef ENEMY_H
#define ENEMY_H
#include "Species/Engimon.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Species/Skill.hpp"
#include "Species/Squirtle.hpp"
#include "Map/Occupier.hpp"

class Enemy  : public Occupier
{
	private:
		Engimon* engimon;
		CellType cellType;
	public:
		Enemy(Map&, int jenis, int level);
		ElementType getElement();
		int getLevel();
		bool setPositionOcc(int, int);
		bool move(int);
		~Enemy();

};
#endif