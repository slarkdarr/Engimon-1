#include "ListEnemy.hpp"
#include "Map/Occupier.hpp"
#include <string>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "time.h"
#include "Battle.hpp"



ListEnemy::ListEnemy(Map& m, Player& player)
{
    this->map = &m;
	this->listEnemy = new Enemy*[10];
    this->jmlhMusuh = 10;
}
int abs(int x){
    if (x < 0) return -x;
    return x;
}

ListEnemy::ListEnemy(Map& m, Player& player, int size)
{
    this->map = &m;
    this->currentplayer = &player;
	this->listEnemy = new Enemy*[size];
    this->jmlhMusuh = size;
    srand(time(0));
    for (int i = 0; i < size; i++)
    {
        // Ngerandom dari 0-4 untuk tipe;
        // Ngerandom dari  (player level-2) - (player level + 2) 
        this->listEnemy[i] = new Enemy(m, rand() % 5, abs(rand() % (player.getLevel() + 5) + (player.getLevel() - 5)));
    }
    
}
	
ListEnemy::~ListEnemy()
{
	for (int i = 0; i < jmlhMusuh; i++)
    {
        delete this->listEnemy[i];
    }

    delete[] this->listEnemy;
}

bool ListEnemy::deleteEnemy(int no)
{
    if (no >= this->jmlhMusuh || no < 0) return false;
    delete this->listEnemy[no];
    this->listEnemy[no] = nullptr;
    return true;
}

void ListEnemy::respawnEnemy()

{
    srand(time(0));
    for (int i = 0; i < jmlhMusuh; i++)
    {
        // Jika engimon tidak ada (bukan null ptr)
        if (!this->listEnemy[i]->getEngimon()){
            // menghapus alokasi memori occupier
            delete this->listEnemy[i];
            // Membuat ulang enemy baru random
            this->listEnemy[i] = new Enemy((*map), rand() % 5, 
            abs(rand() % ((*currentplayer).getLevel() + 5) + 
            ((*currentplayer).getLevel() - 5)));
            std::cout << "berhasi merespawn enemy" << endl;
            break;
        }
    }
    
}



void ListEnemy::moveAllRandom()
{
    for (int i = 0; i < this->jmlhMusuh ; i++) this->listEnemy[i]->move(rand() % 4);
}


// Contoh driver move
int main(int argc, char const *argv[])
{
    Map* isekai = new Map("src/Map/map2.txt");
    Player* lumine = new Player(*isekai,5,5);
    ListEnemy* listMusuh = new ListEnemy(*isekai, *lumine, 20);


    string input;
    bool ashiap = true;
    while (ashiap)
    {
        system("CLS");
        isekai->printMap(lumine->getLevel());
        bool cond = false;

        do
        {
            std::cout << ">> ";
            std::cin >> input;
            if (input == "battle") 
            {
                cond = Battle::battle(*lumine, *listMusuh);
            }
            else cond = lumine->move(input);
        }
        while (!cond);
        listMusuh->moveAllRandom();
    }
    
    return 0;
}