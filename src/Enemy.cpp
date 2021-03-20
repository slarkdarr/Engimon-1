#include "Enemy.hpp"  
#include <stdlib.h>

Enemy::Enemy(Map& m, int angka, int level) : Occupier(m)
{
	switch (angka)
	{
	case 0:
		this->engimon = new Dragon();
		break;
	case 1:
		this->engimon = new Squirtle();
		break;
	case 2:
		this->engimon = new Raichu();
		break;
	case 3:
		this->engimon = new Excadrill();
		break;
	case 4:
		this->engimon = new Articuno();
		break;			
	default:
		this->engimon = new Dragon();
		break;
	}
	switch (this->engimon->getFirstElement())
	{
	case Water:
	case Ice:
		this->cellType = Sea_Cell;
		break;
	default:
		this->cellType = Grassland_Cell;
		break;
	}
	int posisirand = 0;
	do {
		posisirand = rand() % (Position::MAX_X * Position::MAX_Y);

	} while (this->cellType != this->m->cells[posisirand].cellType || !this->setPositionOcc(posisirand % Position::MAX_X, posisirand / Position::MAX_X)) ;
	
	this->engimon->setLevel(level); 
}

ElementType Enemy::getElement()
{
	return this->engimon->getFirstElement();
}
int Enemy :: getLevel() 
{
	return this->engimon->getLevel();
}
	
Enemy::~Enemy()
{
	delete engimon;
}