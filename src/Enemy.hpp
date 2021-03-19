#ifndef ENEMY_H
#define ENEMY_H
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "Map/Occupier.hpp"
class Enemy  : public Occupier
{
	private:
		Engimon* engimon;
		Map* map;
	public:
		Enemy(Map&, ElementType, int x, int y);
		~Enemy();

};
#endif