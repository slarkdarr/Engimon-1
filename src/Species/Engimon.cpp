#include <iostream>
#include <string>
#include "Engimon.hpp"
#include "Skill.hpp"
using namespace std;

Engimon::Engimon(){
    this->monLevel = 0;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon::Engimon(string monName){
    this->monName = monName;
    this->namaSpecies = "";
    this->monLevel = 5;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon::Engimon(string monName, const Engimon& parent1, const Engimon& parent2){
    this->monName = monName;
    this->monLevel = 5;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon& Engimon::operator=(const Engimon& other){
    this->monName = other.getName();
    this->namaSpecies = other.getNamaSpecies();
    this->monLevel = other.monLevel;
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
    return None;
}

Engimon :: ~Engimon(){

}

ostream& operator<<(ostream& os, const Engimon& e){
    os << "Engimon || Nama : " << e.getName() << " || Spesies : " << e.getNamaSpecies() << " || Level : " << e.getLevel();
    return os;
}
void Engimon::printInfo() {
    cout << "Nama : " << this->monName << endl;
    cout << "Nama Spesies" << this->namaSpecies << endl;
    cout << "Level : " << this->monLevel << endl;
    cout << "Exp : " << this->monExp << endl;
    cout << "Cumulative Exp : " << this->monCtvExp << endl;
}
