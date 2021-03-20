#include "ListEnemy.hpp"
#include "Map/Occupier.hpp"
#include <string>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"

ListEnemy::ListEnemy(Map& m, Player& player)
{
    this->map = &m;
	this->listEnemy = new Enemy*[10];
    this->jmlhMusuh = 10;
}

ListEnemy::ListEnemy(Map& m, Player& player, int size)
{
    this->map = &m;
    this->currentplayer = &player;
	this->listEnemy = new Enemy*[size];
    this->jmlhMusuh = size;
    for (int i = 0; i < size; i++)
    {
        // Ngerandom dari 0-4 untuk tipe;
        // Ngerandom dari  (player level-2) - (player level + 2) 
        this->listEnemy[i] = new Enemy(m, rand() % 5, rand() % (player.getLevel() + 2) + (player.getLevel() - 2));
    }
    
}
	
ListEnemy::~ListEnemy()
{
	delete[] this->listEnemy;
}

void ListEnemy::moveAllRandom()
{
    for (int i = 0; i < this->jmlhMusuh ; i++) this->listEnemy[i]->move(rand() % 4);
}

// Contoh driver move
// int main(int argc, char const *argv[])
// {
//     Map* isekai = new Map("src/Map/map.txt");
//     Player* lumine = new Player(*isekai,5,5);
//     ListEnemy* listMusuh = new ListEnemy(*isekai, *lumine, 20);
//     string input;
//     bool ashiap = true;
//     while (ashiap)
//     {
//         system("CLS");
//         isekai->printMap(lumine->getLevel());
//         do
//         {
//             std::cout << ">> ";
//             std::cin >> input;
//         }
//         while (!lumine->move(input));
//         listMusuh->moveAllRandom();
//     }
    
//     return 0;
// }