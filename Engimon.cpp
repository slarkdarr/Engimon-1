#include <iostream>
#include <string>
#include "EngimonDex.h"
#include "Engimon.h"
#include "Skill.h"
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
Engimon :: ~Engimon(){

}
/*void Engimon::print() {
    cout << "Name: " << this->monName << endl;
    cout << "Species: " << this->monSpecies << endl;
}*/
