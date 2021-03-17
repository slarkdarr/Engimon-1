#include <iostream>
#include <string>
#include "EngimonDex.h"
#include "Engimon.h"
#include "Skill.h"
using namespace std;

Engimon::Engimon() : EngimonDex::EngimonDex(){
    this->monParents = new EngimonDex[2];
    this->monSkills = new Skill[4];
    this->monLevel = 0;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon::Engimon(string monName) : EngimonDex::EngimonDex(monName){
    this->monParents = new EngimonDex[2];
    this->monSkills = new Skill[4];
    for (int i = 0; i < 4; i++){
        this->monSkills[i] = Skill("Flamethrower");
    }
    this->monLevel = 5;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon::Engimon(string monName, const Engimon& parent1, const Engimon& parent2) : EngimonDex::EngimonDex(monName){
    this->monParents = new Engimon[2];
    this->monParents[0] = parent1;
    this->monParents[1] = parent2;
    this->monSkills = new Skill[4];
    this->monLevel = 5;
    this->monExp = 0;
    this->monCtvExp = 0;
}

Engimon& Engimon::operator=(const Engimon& other){
    this->EngimonDex::operator=(other);
    for (int i = 0; i < 2; i++){
        this->monParents[i] = other.monParents[i];
    }
    for (int j = 0; j < 4; j++){
        this->monSkills[j] = other.monSkills[j];
    }
    this->monLevel = other.monLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
}

void Engimon::print() {
    cout << "Name: " << this->monName << endl;
    cout << "Species: " << this->monSpecies << endl;
}
