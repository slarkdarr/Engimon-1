#include "Battle.hpp"
#include <iostream>
using namespace std;

float maxFloat(float a, float b)
{
    if (a > b) return a;
    return b;
}

float maxElAdv(Engimon* a, Engimon* b)
{
    ElementType ela1 = a->getFirstElement();
    ElementType ela2 = a->getSecondElement();
    ElementType elb1 = b->getFirstElement();
    ElementType elb2 = b->getSecondElement();

    float elAdvA[4] = 
    {
        Element::elementAdv[make_pair(ela1, elb1)],
        Element::elementAdv[make_pair(ela1, elb2)],
        Element::elementAdv[make_pair(ela2, elb2)],
        Element::elementAdv[make_pair(ela2, elb1)]
    };

    float elAdvAMax = elAdvA[0];
    for (int i = 1; i < 4; i++)
    {
        elAdvAMax = maxFloat(elAdvA[i], elAdvAMax);
    }
    return elAdvAMax;
}

Player* Battle::battle(Player* myplayer, ListEnemy& listmusuh){
    // cout << "BATTLE!" << endl;
    Engimon* engimonMusuh = myplayer->getClosestEnemy();
    // cout << "Berhasil menemukan musuh!" << endl;
    // Jika ada musuh (tidak null ptr)
    if (engimonMusuh)
    {
        ulanglagi:
        auto myengimon = myplayer->getEngimon();

        int playerLvl = myplayer->getLevel();
        int enemyLvl = engimonMusuh->getLevel();

        float playerMaxElAdv = maxElAdv(myengimon,engimonMusuh);
        float enemyMaxElAdv = maxElAdv(engimonMusuh,myengimon);
        
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
            std::cout << "Engimon Di Kalahkan\n";
            
            if (!myplayer->inventory->isFull())
            {
                std::cout << "Engimon Menjadi Milik Anda" << std::endl;
                std::cout << "Beri Nama Engimon Baru anda : ";
                string nama;
                std::cin >>  nama;
                engimonMusuh->setName(nama);
                myplayer->inventory->addEngimon(*engimonMusuh);
                std::cout << std::endl;
            }
            else 
            {
                std::cout << "Inventory Penuh!" << std::endl;
                delete engimonMusuh;
            }
            // RESPAWN MUSUH
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
                myplayer->setActiveEngimon(nullptr);
            }
        }
    }
    return myplayer;
}