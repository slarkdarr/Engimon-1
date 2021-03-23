#include "Player.hpp" 
#include <string>
#include <iostream>
#include "Inventory.hpp"
#include "Map/Occupier.hpp"


Player::Player(Map &m) : Occupier(m, 5, 5, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    this->activeEngimon->setPositionOcc(5,6);
    this->inventory = new Inventory<Skill, Engimon>();


}

Player::Player(Map &m, int x, int y) : Occupier(m, x, y, Player_Type)
{
    Dragon* temp = new Dragon("Charizard");
    this->activeEngimon = new ActiveEngimon(m,*temp);
    if (x == 0 ) this->activeEngimon->setPositionOcc(1,y);
    else this->activeEngimon->setPositionOcc(x-1,y);
    this->inventory = new Inventory<Skill, Engimon>();

}

int Player::getLevel()
{
    return activeEngimon->getLevel();
}

ElementType Player::getElement()
{
    return activeEngimon->engimon->getFirstElement();
}

bool Player::setPositionOcc(int x, int y)
{
    if (Position::isValidCoordinate(x,y))
    {
        if (m->cells[x + y * Position::MAX_X].occupier == this->activeEngimon || !m->cells[x + y * Position::MAX_X].occupier)
        {
            m->cells[this->position.x + this->position.y * Position::MAX_X].setOccupier(nullptr);
            this->activeEngimon->setPositionOcc(this->position.x, this->position.y);
            m->cells[x + y * Position::MAX_X].setOccupier(this);
            this->position.setPosition(x,y);
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

        if (x >= (this->position.x-1) && x <= (this->position.x+1) && y >= (this->position.y-1) && y <= (this->position.y+1)) 
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
        int n;
        while (true) 
        {
            
            std::cout << "Pilih Musuh : ";
            cin >> n;
            try 
            {
                // JIKA gagal, reset input buffer
                if (std::cin.fail()) 
                {
                    cin.clear();
                    cin.ignore(INT_MAX,'\n');
                    throw "Masukkan angka";
                }
                else if (n <= 0 || n > jumlahMusuh) throw "Masukkan angka yang valid";
                else return listmusuh[n-1]->getEngimon();
            }
            catch (char const* error)
            {
                std::cerr << error << std::endl;
                continue;
            }
            
        }
    }
}


	
Player::~Player()
{
    delete this->activeEngimon;
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
