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
    Dragon* temp = new Dragon("Charizard",asik,batu);
    Squirtle* temp2 = new Squirtle("Kura-kura");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    this->activeEngimon->setPositionOcc(5,6);
    this->inventory = new Inventory<Skill, Engimon>();
    this->inventory->addEngimon(*temp2);

}

Player::Player(Map &m, int x, int y) : Occupier(m, x, y, Player_Type)
{
    Squirtle* temp2 = new Squirtle("Kura-kura");
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    if (x == 0 ) this->activeEngimon->setPositionOcc(1,y);
    else this->activeEngimon->setPositionOcc(x-1,y);
    this->inventory = new Inventory<Skill, Engimon>();
    this->inventory->addEngimon(*temp2);

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
        string input;
        std::cout << "Beri nama pada anak engimon: ";
        std::cin >> input;
        Engimon* anak = new Engimon(input, *enji1, *enji2);
        this->inventory->addEngimon(*anak);
    }
}

void Player::removeItem()
{
    this->inventory->printItem();

    if (!this->inventory->isEmpty())
    {
        std::cout << "0. Kembali " << std::endl;
        std::cout << "1. Buang Skill " << std::endl;
        std::cout << "2. Buang Engimon " << std::endl;
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
} 

bool Player::setEngimon()
{
    if (this->inventory->isEngimonBagEmpty()) {std::cout <<"tidak ada engimon lain"<< std::endl; return false;}
    this->inventory->printAllEngimonInfo();
    Bag<Engimon>* temp = this->inventory->listEngimon();
    int n1 = validasiInput("Pilih Engimon: ", 0 , temp->neff, -1);
    Engimon* temp2 = new Engimon(*temp->listItem[n1-1]);
    this->inventory->removeEngimon(n1);
    this->inventory->addEngimon(*this->getEngimon());
    this->setActiveEngimon(temp2);
    delete temp;
    return true;
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
    std::string possibleWords[] = {"AYO KITA PASTI MENANG","GORENG-GORENG DULU GA SIH ?", "ASHIAPPPP !!", "CHUAKKZZZZ", "LET'S GET IT",
    "LET'S CONQUER THE LAND OF DAWN", "OM TELOLET OM", "ANJAY MABAR HAYUU"};
    srand(time(0));
    return possibleWords[rand() % 8];
};

void Player::interact()
{
    cout << this->getEngimon()->getName() << ": " << randomKata() << endl;
}


	
Player::~Player()
{
    delete this->activeEngimon;
}
