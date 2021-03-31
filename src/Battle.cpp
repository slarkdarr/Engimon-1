#include "Battle.hpp"
#include <iostream>
#include <time.h>
using namespace std;

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

        float playerMaxElAdv = Engimon::maxElAdv(myengimon,engimonMusuh);
        float enemyMaxElAdv = Engimon::maxElAdv(engimonMusuh,myengimon);
        
        float powerPlayer = (playerLvl * playerMaxElAdv) + myengimon->sumSkillPower();
        float powerEnemy = (enemyLvl * enemyMaxElAdv) + engimonMusuh->sumSkillPower();
        std::cout << "Power Engimon Anda: " << powerPlayer << endl;
        std::cout << "Power Engimon Lawan: " << powerEnemy << endl;
        if (powerPlayer < powerEnemy)
        {
            std::cout << "Kalah power, Engimon Anda Mati" << std::endl;
            // Jika tidak ada engimon tersisa
            if (myplayer->inventory->isEngimonBagEmpty())
            {
                std::cout << "Tidak Ada Engimon Tersisa" << std::endl;
                delete myplayer->getEngimon();
                myplayer->setActiveEngimon(nullptr);
                delete myplayer;
                return nullptr;
            }
            else
            {   
                try
                {
                    delete myplayer->getEngimon();
                    myplayer->setActiveEngimon(nullptr);
                    myplayer->inventory->printAllEngimonInfo();
                    Bag<Engimon>* temp = myplayer->inventory->listEngimon();
                    int n1 = Player::validasiInput("Pilih Engimon: ", 0 , temp->neff, -1);
                    Engimon* temp2 = new Engimon(*temp->listItem[n1-1]);
                    myplayer->inventory->removeEngimon(n1);
                    myplayer->setActiveEngimon(temp2);
                    delete temp;
                }
                catch(const std::bad_alloc& e)
                {
                    std::cerr << "Bad Alloc terdeteksi, battle di batalkan" <<e.what() << '\n';
                    return myplayer;   
                }
                goto ulanglagi;

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
                Skill* skillbaru = dropRandomSkill();
                std::cout << "Mendapatkan drop: " << std::endl;
                std::cout << *skillbaru << std::endl;
                if (!myplayer->inventory->isFull()) {
                    myplayer->inventory->addSkill(*skillbaru);
                }
                else
                {
                    std::cout << "Inventory Penuh! Skill tidak dapat dimasukkan" << std::endl;
                }
                delete skillbaru;
                
                std::cout << std::endl;
            }
            else 
            {
                std::cout << "Inventory Penuh!" << std::endl;
                std::cout << "Skill & Engimon tidak dapat dimasukkan" << std::endl;
            }
            delete engimonMusuh;

            // RESPAWN MUSUH
            srand(time(0));
            for (int i = 0; i < listmusuh.jmlhMusuh; i++)
            {
                if (listmusuh.listEnemy[i]->getEngimon() == engimonMusuh)
                {
                    listmusuh.listEnemy[i]->setEngimon(nullptr);
                    delete listmusuh.listEnemy[i];
                    listmusuh.listEnemy[i] = new Enemy(*listmusuh.map, 
                    rand() % 7, abs(rand() % (myplayer->getLevel() + 5) + (myplayer->getLevel() - 5)));
                    break;
                }
            }
            // Jika Engimon Suicide saat Penambahan xp
            if (!myplayer->getEngimon()->addExp(100))
            {
                myplayer->setActiveEngimon(nullptr);
                myplayer->inventory->printAllEngimonInfo();
                Bag<Engimon>* temp = myplayer->inventory->listEngimon();
                int n1 = Player::validasiInput("Pilih Engimon: ", 0 , temp->neff, -1);
                Engimon* temp2 = new Engimon(*temp->listItem[n1-1]);
                myplayer->inventory->removeEngimon(n1);
                myplayer->setActiveEngimon(temp2);
                delete temp;
            }
        }
    }
    return myplayer;
}

Skill* Battle::dropRandomSkill()
{
    Skill* skillBaru;
    srand(time(0));
    int random = rand() % 11;
    switch (random)
    {
    case 0:
        skillBaru = new Cataclysm();
        break;
    case 1:
        skillBaru = new Fissure();
        break;
    case 2:
        skillBaru = new IceVortex();
        break;
    case 3:
        skillBaru = new Magnetize();
        break;
    case 4:
        skillBaru = new Nimbus();
        break;
    case 5:
        skillBaru = new SplinterBlast();
        break;
    case 6:
        skillBaru = new StaticStorm();
        break;
    case 7:
        skillBaru = new Sunstrike();
        break;
    case 8:
        skillBaru = new Torrent();
        break;
    case 9:
        skillBaru = new Waveform();
        break;
    case 10:
        skillBaru = new Skill("AntiAging", "None", 1,1);
    default:
        skillBaru = new Cataclysm();
        break;
    }
    return skillBaru;

}