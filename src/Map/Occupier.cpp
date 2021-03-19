#include "Occupier.hpp"  
#include "Position.hpp"
#include <iostream>
#include <string>

Occupier::Occupier(Map& m)
{
	this->position = Position();
    this->ocpType = Enemy_Type;
    this->m = &m;
    if(!setPositionOcc(0,0)) throw 999;

}

Occupier::Occupier(Map& m, int x, int y, Occupier_Type octype)
{
	this->position = Position(x,y);
    this->ocpType = octype;
    this->m = &m;
    if(!setPositionOcc(x,y)) throw 1998;
}

Occupier :: ~Occupier() 
{
    m->cells[this->position.x + this->position.y * MAX_X].setOccupier(nullptr);
}

	
Position Occupier::getPosition(){
    return this->position;
}

bool Occupier::setPositionOcc(int x, int y)
{
    if (Position::isValidCoordinate(x,y))
    {
        m->cells[this->position.x + this->position.y * MAX_X].setOccupier(nullptr);
        m->cells[x + y * MAX_X].setOccupier(this);
        this->position.setPosition(x,y);
        return true;
    }
    return false;
}

bool Occupier::move(std::string str) 
{
    char c = str[0];
    int x = this->position.x;
    int y = this->position.y;
    switch (c)
    {
    case 'w':
    case 'W':
        return setPositionOcc(x,--y);
    case 'a':
    case 'A':
        return setPositionOcc(--x,y);
    case 's':
    case 'S':
        return setPositionOcc(x,++y);
    case 'd':
    case 'D':
        return setPositionOcc(++x,y);   
    default:
        std::cout << "Salah memasukkan input" << std::endl;
        return false;
    }
}



void Occupier::printPosition()
{
    std::cout << this->position.x << std::endl;
    std::cout << this->position.y << std::endl;
}

// int main(int argc, char const *argv[])
// {
//     Occupier* myobj = new Occupier(5,5);
//     myobj->printPosition();
//     return 0;
// }
