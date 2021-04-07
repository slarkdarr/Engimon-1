#include "Player.hpp" 
#include <string>
#include <iostream>
#include "Inventory.hpp"
#include "Map/Occupier.hpp"
#include "time.h"
#include "Bag.hpp"


int Player::validasiInput(std::string pesan, int batasBawah, int batasAtas, int angkalain)
{
    int n2;
    while (true) 
    {
        
        std::cout << pesan;
        std::cin >> n2;
        try 
        {
            // JIKA gagal, reset input buffer
            if (std::cin.fail()) 
            {
                std::cin.clear();
                std::cin.ignore(INT_MAX,'\n');
                throw "Masukkan angka";
            }
            else if (n2 <= batasBawah || n2 > batasAtas) throw "Masukkan angka yang valid";
            else if (n2 == angkalain) throw "Masukkan angka bukan sebelumnya";
            else return n2;
        }
        catch (char const* error)
        {
            std::cerr << error << std::endl;
            continue;
        } 
    }
    return n2;
}

Player::Player(Map &m) : Occupier(m, 5, 5, Player_Type)
{
    Articuno asik("EsBatu");
    Excadrill batu("batuan");
    Dragon* temp = new Dragon("Charizard");
    Squirtle* temp23 = new Squirtle("Kura-kura");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    this->activeEngimon->setPositionOcc(5,6);
    this->inventory = new Inventory<Skill, Engimon>();
    this->inventory->addEngimon(*temp23);

}

Player::Player(Map &m, int x, int y) : Occupier(m, x, y, Player_Type)
{
    Squirtle* temp23 = new Squirtle("Kura-kura");
    Dragon* temp = new Dragon("Charizard");
    Seismotoad* temp3 = new Seismotoad("Yuhu");
    Kyogre* temp4 = new Kyogre("KyOGRE");
    Raichu* raichu = new Raichu("raichu");
    raichu->setLevel(31);
    temp4->setLevel(31);
    temp->setLevel(31);
    temp23->setLevel(31);
    temp3->setLevel(31);
    Inferail* infernus = new Inferail("Infernus");
    infernus->setLevel(31);
    Inferail* infernus2 = new Inferail("Infernus2");
    infernus2->setLevel(31);
    infernus->addExp(1900);
    infernus->monSkills->masteryLevel = 2;
    this->activeEngimon = new ActiveEngimon(m,*temp);
    if (x == 0 ) this->activeEngimon->setPositionOcc(1,y);
    else this->activeEngimon->setPositionOcc(x-1,y);
    this->inventory = new Inventory<Skill, Engimon>();
    this->inventory->addEngimon(*infernus);
    this->inventory->addEngimon(*infernus2);
    this->inventory->addEngimon(*temp23);
    this->inventory->addEngimon(*temp3);
    this->inventory->addEngimon(*raichu);
    this->inventory->addEngimon(*temp4);

}

int Player::getLevel()
{
    return activeEngimon->getLevel();
}

ElementType Player::getElement1()
{
    return activeEngimon->engimon->getFirstElement();
}
ElementType Player::getElement2()
{
    return activeEngimon->engimon->getSecondElement();
}

bool Player::setPositionOcc(int x, int y)
{
    if (Position::isValidCoordinate(x,y))
    {
        if (m->cells[x + y * Position::MAX_X].occupier == this->activeEngimon || !m->cells[x + y * Position::MAX_X].occupier)
        {
            m->cells[this->position->x + this->position->y * Position::MAX_X].setOccupier(nullptr);
            this->activeEngimon->setPositionOcc(this->position->x, this->position->y);
            m->cells[x + y * Position::MAX_X].setOccupier(this);
            this->position->setPosition(x,y);
            return true;
        }
        std::cout << "Cell ditempati!" << std::endl;
        return false;
    }
    std::cout << "MENTOK BOS!" << std::endl;
    return false;
}

void Player::setActiveEngimon(Engimon* m)
{
    this->activeEngimon->setEngimon(m);
}

void Player::printActiveEngimon()
{
    this->activeEngimon->engimon->printInfo();
}


void Player::breeding()
{
    if (this->inventory->isEngimonBagEmpty()) cout<<"Jumlah engimon tidak mencukupi"<<endl;
    else if (this->inventory->isFull()) cout << "Inventory Penuh!!" << endl;
    else
    {
        Bag<Engimon>* temp = this->inventory->listEngimon();
        temp->Add(*this->getEngimon());
        temp->printAllInfo();
        int n1 = validasiInput("Pilih Engimon 1: ", 0 , temp->neff, -1);
        int n2 = validasiInput("Pilih Engimon 2: ", 0 , temp->neff, n1);
        // Logic breeding
        Engimon* enji1 = temp->listItem[n1-1];
        Engimon* enji2 = temp->listItem[n2-1];
        if (enji1->getLevel() < 30 || enji2->getLevel() < 30)
        {
            std::cout << "Level Engimon Tidak Mencukupi" << std::endl;
            return; 
        }
        enji1->setLevel(enji1->getLevel() - 30);
        enji2->setLevel(enji2->getLevel() - 30);
        string input;
        std::cout << "Beri nama pada anak engimon: ";
        std::cin >> input;
        Engimon* anak = new Engimon(input, *enji1, *enji2);
        this->inventory->addEngimon(*anak);
        delete anak;
    }
}

void Player::removeItem()
{
    this->inventory->printItem();

    if (!this->inventory->isEmpty())
    {
        std::cout << std::endl;
        std::cout << "0. Kembali " << std::endl;
        std::cout << "1. Buang Skill " << std::endl;
        std::cout << "2. Buang Engimon " << std::endl;
        try
        {
            int num = validasiInput("Pilih Opsi: ",-1,2,-1);
            switch (num)
            {
            case 1:
                if (!this->inventory->isBagSkillsEmpty()) 
                {
                    int num2 = validasiInput("Pilih skill untuk dibuang: ", -1,9999,-1);
                    if (num2 == 0) break;
                    this->inventory->removeSkill(num2);
                }
                break;
            case 2:
                if (!this->inventory->isEngimonBagEmpty()) 
                {
                    int num2 = validasiInput("Pilih Engimon untuk dibuang: ", -1,9999,-1);
                    if (num2 == 0) break;
                    this->inventory->removeEngimon(num2);
                }
                break;
            default:
                break;
            }
        }
        catch(const std::bad_alloc& e)
        {
            std::cerr << "Bad alloc terdeksi, gagal membuang item " << e.what() << std::endl;
        }
    }
}
void Player::useSkill()
{
    if (this->inventory->isBagSkillsEmpty()) {std::cout <<"tidak ada skill lain"<< std::endl; return;}
    this->inventory->printAllSkillInfo();
    Bag<Skill>* temp = this->inventory->listSkill();
    int n1 = validasiInput("Pilih Skill: ", 0 , temp->neff, -1);
    Skill skilltemp;
    skilltemp = *temp->listItem[n1-1];
    if (this->getEngimon()->learnSkill(skilltemp)) this->inventory->removeSkill(n1);
    delete temp;
} 

bool Player::setEngimon()
{
    if (this->inventory->isEngimonBagEmpty()) {std::cout <<"tidak ada engimon lain"<< std::endl; return false;}
    this->inventory->printAllEngimonInfo();
    Bag<Engimon>* temp = this->inventory->listEngimon();
    int n1 = validasiInput("Pilih Engimon: ", 0 , temp->neff, -1);
    Engimon* engimonlama = temp->listItem[n1-1];
    cout << "Engimon Lama" << endl;
    cout << *engimonlama << endl;
    try
    {
        Engimon* temp23 = new Engimon(*engimonlama);
        // *temp23 = *engimonlama;
        cout << "Engimon Baru" << endl;
        cout << *temp23 << endl;
        this->inventory->removeEngimon(n1); // engimon lama
        Engimon* enjimonskrng = this->getEngimon();
        this->inventory->addEngimon(*this->getEngimon());
        this->setActiveEngimon(temp23);
        delete enjimonskrng;
        delete temp;
        return true;
    }
    catch(const std::bad_alloc& e)
    {
        std::cerr << "Bad alloc terdeksi, gagal menset engimon " << e.what() << std::endl;
        return false;
    }
}


Engimon* Player::getEngimon()
{
    return this->activeEngimon->engimon;
}

Engimon* Player::getClosestEnemy()
{
    Occupier** listmusuh = new Occupier*[8];
    int jumlahMusuh = 0;
    for (int i = 0; i < Position::MAX_X * Position::MAX_Y; i++)
    {
        int x = i % Position::MAX_X;
        int y = i / Position::MAX_X;

        if (x >= (this->position->x-1) && x <= (this->position->x+1) && y >= (this->position->y-1) && y <= (this->position->y+1)) 
        {
            if ((this->m->cells[i].occupier) && this->m->cells[i].occupier->ocpType == Enemy_Type) 
            {
                listmusuh[jumlahMusuh] = m->cells[i].occupier;
                jumlahMusuh++;
            }
        } 
    }

    switch (jumlahMusuh)
    {
    case 0:
        std::cout << "Tidak ada musuh disekitar" << std::endl;
        return nullptr;
    case 1:
        listmusuh[0]->getEngimon()->printInfoSafe();
        return listmusuh[0]->getEngimon();
    default:
        std::cout << "Ditemukan " << jumlahMusuh  << " Musuh!"<< std::endl;
        for (int i = 0; i < jumlahMusuh; i++)
        {
           std::cout << (i+1) << "." << std::endl;
           listmusuh[i]->getEngimon()->printInfoSafe(); 
           std::cout << std::endl;
        }
        int n = validasiInput("Pilih Musuh : ", 0, jumlahMusuh, -1);
        return listmusuh[n-1]->getEngimon();
    }
}

std::string randomKata() {
    std::string possibleWords[] = 
    {
        "AYO KITA PASTI MENANG",
        "GORENG-GORENG DULU GA SIH ?",
        "ASHIAPPPP !!", "CHUAKKZZZZ", 
        "LET'S GET IT",
        "LET'S CONQUER THE LAND OF DAWN", 
        "OM TELOLET OM", 
        "ANJAY MABAR HAYUU"
    };
    srand(time(0));
    return possibleWords[rand() % 7];
};

void Player::interact()
{
    cout << this->getEngimon()->getName() << ": " << randomKata() << endl;
}


	
Player::~Player()
{
    delete this->activeEngimon;
}
