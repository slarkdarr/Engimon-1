#include "Player.hpp" 
#include <string>
#include <iostream>


	
Player::Player(Map &m) : Occupier(m, 5, 5, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    this->activeEngimon->setPositionOcc(5,6);
    this->listengimon.push_back(*temp);
}

Player::Player(Map &m, int x, int y) : Occupier(m, x, y, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    this->listengimon.push_back(*temp);
    if (x == 0 ) this->activeEngimon->setPositionOcc(1,y);
    else this->activeEngimon->setPositionOcc(x-1,y);
}

int Player::getLevel()
{
    return activeEngimon->getLevel();
}

ElementType Player::getElement()
{
    return activeEngimon->engimon->getFirstElement();
}

bool Player::setPositionOcc(int x, int y)
{
    if (Position::isValidCoordinate(x,y))
    {
        if (m->cells[x + y * Position::MAX_X].occupier == this->activeEngimon || !m->cells[x + y * Position::MAX_X].occupier)
        {
            m->cells[this->position.x + this->position.y * Position::MAX_X].setOccupier(nullptr);
            this->activeEngimon->setPositionOcc(this->position.x, this->position.y);
            m->cells[x + y * Position::MAX_X].setOccupier(this);
            this->position.setPosition(x,y);
            return true;
        }
        std::cout << "Cell ditempati!" << std::endl;
        return false;
    }
    std::cout << "MENTOK BOS!" << std::endl;
    return false;
}

void Player::setActiveEngimon(Engimon& m){
    this->activeEngimon->setEngimon(m);
}

	
Player::~Player()
{
    listengimon.clear();
}
// Contoh driver move
// int main(int argc, char const *argv[])
// {
//     Map* isekai = new Map("src/Map/map.txt");
//     Player* lumine = new Player(*isekai,5,5);

//     string input;
//     bool ashiap = true;
//     while (ashiap)
//     {
//         isekai->printMap(lumine->getLevel());
//         do
//         {
//             std::cout << ">> ";
//             std::cin >> input;
//         }
//         while (!lumine->move(input));
//     }
    
//     return 0;
// }
