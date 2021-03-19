#include "Occupier.hpp"  
#include "Position.hpp"
#include <iostream>

Occupier::Occupier(Map& m)
{
	this->position = Position();
    this->ocpType = Unknown;
    if(!setPositionOcc(m,0,0)) throw 1;
}

Occupier::Occupier(Map& m, int x, int y, Occupier_Type octype)
{
	this->position = Position(x,y);
    this->ocpType = octype;
    if(!setPositionOcc(m,x,y)) throw 1;
}
	
Position Occupier::getPosition(){
    return this->position;
}

bool Occupier::setPositionOcc(Map& m, int x, int y){
    if (Position::isValidCoordinate(x,y))
    {
        m.cells[this->position.x + this->position.y * MAX_X].setOccupier(nullptr);
        m.cells[x + y * MAX_X].setOccupier(this);
        this->position.setPosition(x,y);
        return true;
    }
    return false;
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
