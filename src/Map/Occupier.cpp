#include "Occupier.hpp"  
#include "Position.hpp"
#include <iostream>
#include <string>

Occupier::Occupier(Map& m)
{
	this->position = Position();
    this->ocpType = Enemy_Type;
    this->m = &m;
    if(!setPositionOcc(0,0)) 
    {
        std::cout << "error spawn x:0 y:0" << std::endl;
        throw 999;
    }
}

Occupier::Occupier(Map& m, int x, int y, Occupier_Type octype)
{
	this->position = Position(x,y);
    this->ocpType = octype;
    this->m = &m;
    if(!setPositionOcc(x,y)) 
    {
        std::cout << "error spawn x:"<< x << " y:" << y << std::endl;
        throw 1998;
    }
}

Occupier :: ~Occupier() 
{
    m->cells[this->position.x + this->position.y * Position::MAX_X].setOccupier(nullptr);
}

	
Position Occupier::getPosition(){
    return this->position;
}

bool Occupier::setPositionOcc(int x, int y)
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
