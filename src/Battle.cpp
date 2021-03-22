#include "Battle.hpp"
#include <iostream>
using namespace std;

float maxFloat(float a, float b)
{
    if (a > b) return a;
    return b;
}

Player* Battle::battle(Player* myplayer, ListEnemy& listmusuh){
    // cout << "BATTLE!" << endl;
    Engimon* engimonMusuh = myplayer->getClosestEnemy();
    // cout << "Berhasil menemukan musuh!" << endl;
    // Jika ada musuh (tidak null ptr)
    if (engimonMusuh)
    {
        ulanglagi:
        ElementType elPlayer1 =  myplayer->getEngimon()->getFirstElement();
        ElementType elPlayer2 =  myplayer->getEngimon()->getSecondElement();
        ElementType elMusuh1 = engimonMusuh->getFirstElement();
        ElementType elMusuh2 = engimonMusuh->getSecondElement();

        int playerLvl = myplayer->getLevel();
        int enemyLvl = engimonMusuh->getLevel();

        float playerElmAdv[4] = 
        {
            Element::elementAdv[std::make_pair(elPlayer1, elMusuh1)],
            Element::elementAdv[std::make_pair(elPlayer1, elMusuh2)],
            Element::elementAdv[std::make_pair(elPlayer2, elMusuh2)],
            Element::elementAdv[std::make_pair(elPlayer2, elMusuh1)]
        };

        float enemyElmAdv[4] = 
        {   
            Element::elementAdv[std::make_pair(elMusuh1, elPlayer1)],
            Element::elementAdv[std::make_pair(elMusuh1, elPlayer2)],
            Element::elementAdv[std::make_pair(elMusuh2, elPlayer2)],
            Element::elementAdv[std::make_pair(elMusuh2, elPlayer1)]
        };

        float playerMaxElAdv = playerElmAdv[0];
        float enemyMaxElAdv = enemyElmAdv[0];

        for (int i = 1; i < 4; i++)
        {
            playerMaxElAdv = maxFloat(playerElmAdv[i], playerMaxElAdv);
            enemyMaxElAdv = maxFloat(enemyElmAdv[i], enemyMaxElAdv);
        }
        
        float powerPlayer = playerLvl * playerMaxElAdv; // + SUM(every skill’s base power * Mastery Level)
        float powerEnemy = enemyLvl * enemyMaxElAdv; // + SUM(every skill’s base power * Mastery Level)

        if (powerPlayer < powerEnemy)
        {
            std::cout << "Kalah power, Engimon Anda Mati" << std::endl;
            delete myplayer->getEngimon();

            myplayer->setActiveEngimon(nullptr);


            // Jika tidak ada engimon tersisa
            if (myplayer->inventory->isEngimonBagEmpty())
            {
                std::cout << "Tidak Ada Engimon Tersisia" << std::endl;
                delete myplayer;
                return nullptr;
            }
            else
            {   
                myplayer->inventory->printAllEngimonInfo();
                // goto ulanglagi;
            }
        }
        // Jika Menang Power
        else
        {
            if (!myplayer->inventory->isFull())
            {
                if(myplayer->inventory->addEngimon(*engimonMusuh))
                {
                    std::cout << "Beri Nama Engimon Baru anda : ";
                    string nama;
                    std::cin >>  nama;
                    engimonMusuh->setName(nama);
                    std::cout << std::endl;
                }
            }
            else delete engimonMusuh;

            for (int i = 0; i < listmusuh.jmlhMusuh; i++)
            {
                if (listmusuh.listEnemy[i]->getEngimon() == engimonMusuh)
                {
                    listmusuh.listEnemy[i]->setEngimon(nullptr);
                    delete listmusuh.listEnemy[i];
                    listmusuh.listEnemy[i] = new Enemy(*listmusuh.map, 
                    rand() % 5, abs(rand() % (myplayer->getLevel() + 5) + (myplayer->getLevel() - 5)));
                    break;
                }
            }
            // Jika Engimon Suicide saat Penambahan xp
            if (!myplayer->getEngimon()->addExp(100))
            {

            }
        }
        return myplayer;
    }
    return myplayer;
}