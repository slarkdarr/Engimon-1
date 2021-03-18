#include "Occupier.hpp"  
#include "Map/Position.hpp"
#include <iostream>

Occupier::Occupier()
{
	this->position = Position();
    this->ocpType = Unknown;
    level = 1;
}

Occupier::Occupier(int x, int y, int level, Occupier_Type octype)
{
	this->position = Position(x,y);
    this->ocpType = octype;
    this->level = level;
}
	
Position Occupier::getPosition(){
    return this->position;
}

int Occupier::getLevel(){
    return this->level;
}


bool Occupier::setPosition(int x, int y){
    this->position = Position(x,y);
    return true;
}

void Occupier::printPosition(){
    std::cout << this->position.x << std::endl;
    std::cout << this->position.y << std::endl;
}

// int main(int argc, char const *argv[])
// {
//     Occupier* myobj = new Occupier(5,5);
//     myobj->printPosition();
//     return 0;
// }
