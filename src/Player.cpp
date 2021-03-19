#include "Player.hpp" 
#include <string>
#include <iostream>


	
Player::Player(Map &m) : Occupier(m, 5, 5, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = temp;
    this->listengimon.push_back(*temp);
}

Player::Player(Map &m, int x, int y) : Occupier(m, x, y, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = temp;
    this->listengimon.push_back(*temp);
}

int Player::getLevel()
{
    return activeEngimon->getLevel();
}

ElementType Player::getElement()
{
    return activeEngimon->getFirstElement();
}

	
Player::~Player()
{
    listengimon.clear();
}
// Contoh driver move
// int main(int argc, char const *argv[])
// {
//     Map* isekai = new Map();
//     isekai->setSea(15,30,10,20);
//     Player* lumine = new Player(*isekai,5,5);
//     // isekai->printMap(lumine->getLevel());
//     string input;
//     bool ashiap = true;
//     while (ashiap)
//     {
//         isekai->printMap(lumine->getLevel());
//         do
//         {
//             std::cin >> input;
//         }
//         while (!lumine->move(input));
//     }
//     isekai->printMap(lumine->getLevel());
    

//     return 0;
// }
