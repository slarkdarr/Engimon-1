#include <iostream>
#include "Engimon.hpp"
#include "Raichu.hpp"
#include "../Skill/StaticStorm.hpp"

using namespace std;

void Raichu::InitComp() {
    this->namaSpecies = "Raichu";
    monElements[0].setElement(Electric);
    this->monSkills[0] = StaticStorm();

}

Raichu :: Raichu() : Engimon(){
    InitComp();
};

Raichu :: Raichu(string name) : Engimon(name){
    InitComp();
};

Raichu :: ~Raichu(){

}
