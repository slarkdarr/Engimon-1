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
        std::cout << "Command tersedia: w/a/s/d, battle, list, info, use, throw, set." << std::endl;

        bool cond = true;

        do
        {
            std::cout << ">> ";
            std::cin >> input;
            std::cout << std::endl;

            // Battle
            if (input == "battle") 
            {
                myPlayer = Battle::battle(myPlayer, *listMusuh);
                cond = (myPlayer);
            }
            // breeding
            else if (input == "breeding")
            {
                myPlayer->breeding();
            }
            // print list dari inventory (skill & engimon)
            else if (input == "list")
            {
                myPlayer->inventory->printItem();
            }
            // print info dari engimon saat ini
            else if (input == "info")
            {
                myPlayer->printActiveEngimon();
            }
            // use skill
            else if (input == "use")
            {
                
            }
            // ganti active engimon
            else if (input == "set")
            {
                cond = !myPlayer->setEngimon();
            }
            else if (input == "throw")
            {
                myPlayer->removeItem();
            }
            else cond = (!myPlayer->move(input));
        }
        while (cond);
    }
    std::cout << std::endl;
    std::cout << "GAME OVER!" << std::endl;
    std::cout << "Ingin Bermain lagi? y/n " << std::endl;
    std::cout << ">> ";
    std::cin >> input;
    if (input == "yes" || input == "y") 
    {
        delete listMusuh;
        myPlayer = new Player(*isekai,5,5);
        listMusuh = new ListEnemy(*isekai, myPlayer, 20);
        goto playgame;
    }
    else
    {
        delete listMusuh;
        delete isekai;
    }
    return 0;
}