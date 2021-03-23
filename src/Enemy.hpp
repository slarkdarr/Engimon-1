#ifndef ENEMY_H
#define ENEMY_H
#include "Species/Engimon.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Skill/Skill.hpp"
#include "Species/Squirtle.hpp"
#include "Map/Occupier.hpp"

class Enemy  : public Occupier
{
	private:
		CellType cellType;
	public:
		Engimon* engimon;
		Enemy(Map&, int jenis, int level);

		ElementType getElement();
		int getLevel();
		Engimon* getEngimon();
		void setEngimon(Engimon*);
		bool setPositionOcc(int, int);
		bool move(int);
		~Enemy();

};
#endif