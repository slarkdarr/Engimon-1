#include "ActiveEngimon.hpp"  
	
#include "ActiveEngimon.hpp"  
#include <stdlib.h>

ActiveEngimon::ActiveEngimon(Map& m, Engimon& edgymon) : Occupier(m)
{
	this->engimon = &edgymon;
    this->ocpType = Pet_Type;
	// this->setPositionOcc(posisirand % Position::MAX_X, posisirand / Position::MAX_X)
}

ElementType ActiveEngimon::getElement1()
{
	return this->engimon->getFirstElement();
}
ElementType ActiveEngimon::getElement2()
{
	return this->engimon->getSecondElement();
}
int ActiveEngimon :: getLevel() 
{
	return this->engimon->getLevel();
}

void ActiveEngimon::setEngimon(Engimon* e)
{
	this->engimon = e;
}

Engimon* ActiveEngimon::getEngimon()
{
    return this->engimon;
}


ActiveEngimon::~ActiveEngimon()
{
	delete engimon;
}