#include "Enemy.hpp"  
#include <stdlib.h>
#include "time.h"


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
	srand(time(0));
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

bool Enemy::setPositionOcc(int x, int y)
{
	if (Position::isValidCoordinate(x,y))
    {
        if (!m->cells[x + y * Position::MAX_X].occupier && this->cellType == this->m->cells[x + y * Position::MAX_X].cellType)
        {
            m->cells[this->position.x + this->position.y * Position::MAX_X].setOccupier(nullptr);
            m->cells[x + y * Position::MAX_X].setOccupier(this);
            this->position.setPosition(x,y);
            return true;
        }
        // std::cout << "Cell ditempati!" << std::endl;
        return false;
    }
    // std::cout << "MENTOK BOS!" << std::endl;
    return false;
}
bool Enemy::move(int rand)
{
    int x = this->position.x;
    int y = this->position.y;
    switch (rand)
    {
    case 0:
        return setPositionOcc(x,--y);
    case 1:
        return setPositionOcc(--x,y);
    case 2:
        return setPositionOcc(x,++y);
    case 3:
        return setPositionOcc(++x,y);   
    default:
        return false;
    }
}

void Enemy::setEngimon(Engimon* e)
{
	this->engimon = e;
}

Engimon* Enemy::getEngimon()
{
	return engimon;
}


Enemy::~Enemy()
{
	delete engimon;
}