#include "ActiveEngimon.hpp"  
	
#include "ActiveEngimon.hpp"  
#include <stdlib.h>

ActiveEngimon::ActiveEngimon(Map& m, Engimon& edgymon) : Occupier(m)
{
	this->engimon = &edgymon;
    this->ocpType = Pet_Type;
	// this->setPositionOcc(posisirand % Position::MAX_X, posisirand / Position::MAX_X)
}

ElementType ActiveEngimon::getElement()
{
	return this->engimon->getFirstElement();
}
int ActiveEngimon :: getLevel() 
{
	return this->engimon->getLevel();
}

bool ActiveEngimon::setPositionOcc(int x, int y)
{
	if (Position::isValidCoordinate(x,y))
    {
        if (!m->cells[x + y * Position::MAX_X].occupier)
        {
            m->cells[this->position.x + this->position.y * Position::MAX_X].setOccupier(nullptr);
            m->cells[x + y * Position::MAX_X].setOccupier(this);
            this->position.setPosition(x,y);
            return true;
        }
        return false;
    }
    return false;
}


void ActiveEngimon::setEngimon(Engimon& e)
{
	this->engimon = &e;
}

Engimon* ActiveEngimon::getEngimon()
{
    return this->engimon;
}


ActiveEngimon::~ActiveEngimon()
{
	delete engimon;
}