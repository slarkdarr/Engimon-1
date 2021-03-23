// Contoh driver game
#include "Battle.hpp"

int main(int argc, char const *argv[])
{

    Map* isekai = new Map("src/Map/map2.txt");
    Player* myPlayer = new Player(*isekai,5,5);
    ListEnemy* listMusuh = new ListEnemy(*isekai, myPlayer, 20);

    playgame:
    string input;
    // Selama myPlayer Hidup / != nullptr
    while (myPlayer)
    {
        system("CLS");
        listMusuh->moveAllRandom();
        isekai->printMap(myPlayer->getLevel());
        bool cond = true;

        do
        {
            std::cout << ">> ";
            std::cin >> input;
            if (input == "battle") 
            {
                myPlayer = Battle::battle(myPlayer, *listMusuh);
                cond = (myPlayer);
            }
            else if (input == "breeding")
            {
                
            }
            else if (input == "list")
            {
                myPlayer->inventory->printItem();
            }
            else if (input == "info")
            {
                myPlayer->printActiveEngimon();
            }
            else if (input == "set")
            {
                
            }
            else cond = (!myPlayer->move(input));
        }
        while (cond);
    }
    
    std::cout << "GAME OVER!" << std::endl;
    std::cout << "Ingin Bermain lagi? y/n " << std::endl;
    std::cout << ">> ";
    std::cin >> input;
    if (input == "yes" || input == "y") 
    {
        myPlayer = new Player(*isekai,5,5);
        goto playgame;
    }
    else
    {
        delete listMusuh;
        delete isekai;
    }
    return 0;
}