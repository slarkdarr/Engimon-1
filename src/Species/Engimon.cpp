#include <iostream>
#include <string>
#include "Engimon.hpp"
#include "../Skill/Skill.hpp"

using namespace std;

Engimon::Engimon(){
    this->monName = "";
    this->namaSpecies = "";
    this->monLevel = 1;
    this->baseLevel = 1;
    this->monExp = 0;
    this->monCtvExp = 2000;
    this->monSkills = new Skill[4];
    this->monElements = new Element[2];

}

Engimon::Engimon(string monName){
    this->monName = monName;
    this->namaSpecies = "";
    this->monLevel = 1;
    this->baseLevel = 1;
    this->monExp = 0;
    this->monCtvExp = 2000;
    this->monSkills = new Skill[4];
    this->monElements = new Element[2];

}

Engimon::Engimon(const Engimon& other){
    this->monName = other.monName;
    this->namaSpecies = other.namaSpecies;
    this->monLevel = other.monLevel;
    this->baseLevel = other.baseLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
    this->monSkills = new Skill[4];
    for (int i = 0; i < 4; i++) this->monSkills[i] = other.monSkills[i];
    this->monElements = new Element[2];
    this->monElements[0].setElement(other.monElements[0].getElementType());
    this->monElements[1].setElement(other.monElements[1].getElementType());
}



void Engimon::setName(string name)
{
    this->monName = name;
}

void Engimon::setLevel(int level) {
    this->monLevel = level;
    this->baseLevel = level;
}
bool Engimon::addExp(int additionalExp) {
    int virtualExp = baseLevel * 100;
    this->monExp += additionalExp;
    std::cout << "Anda Mendapatkan " << additionalExp << " exp" << std::endl;  
    if (monExp >= monCtvExp)
    {
        delete this;
        return false;
    }
    else if (this->monLevel != ((this->monExp + virtualExp)/ 100))  {
        this->monLevel = ((this->monExp + virtualExp) / 100);
        std::cout << "LEVEL UP!! Engimon anda naik ke level " 
        << monLevel << std::endl; 
    }
    return true;
}


Engimon& Engimon::operator=(const Engimon& other){
    this->monName = other.getName();
    this->namaSpecies = other.getNamaSpecies();
    this->monLevel = other.monLevel;
    this->baseLevel = other.baseLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
    return *this;
}

string Engimon :: getNamaSpecies() const{
    return namaSpecies;
}
string Engimon :: getName() const{
    return monName;
}
int Engimon :: getLevel() const{
    return this->monLevel;
}

ElementType Engimon :: getFirstElement()
{
    return this->monElements[0].getElementType();
}

ElementType Engimon :: getSecondElement()
{
    return this->monElements[1].getElementType();
}


float Engimon :: sumSkillPower()
{
    float temp = 0;
    for (int i = 0; i < 4; i++)
    {
        temp += (this->monSkills[i].getBasePower() * this->monSkills[i].getMasteryLevel());
    }
    return temp;
}


Engimon :: ~Engimon(){

}

ostream& operator<<(ostream& os, const Engimon& e){
    os << "Engimon || Nama : " << e.getName() << " || Spesies : " << e.getNamaSpecies() << " || Level : " << e.getLevel();
    return os;
}
void Engimon::printInfo() {
    cout << "Nama : " << this->monName << endl;
    printInfoSafe();
    cout << "Exp : " << this->monExp << endl;
    cout << "Maximum Exp : " << this->monCtvExp << endl;
}

void Engimon::printInfoSafe() {
    cout << "Nama Spesies : " << this->namaSpecies << endl;
    cout << "Level : " << this->monLevel << endl;
}