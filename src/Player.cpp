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
