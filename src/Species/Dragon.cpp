#include <iostream>
#include "Engimon.hpp"
#include "Dragon.hpp"
#include "../Skill/Sunstrike.hpp"

using namespace std;

void Dragon::InitComp() {
    this->namaSpecies = "Dragon";
    monElements[0].setElement(Fire);
    this->monSkills[0] = Sunstrike();
}

Dragon :: Dragon() : Engimon(){
    InitComp();
};

Dragon :: Dragon(string name) : Engimon(name){
    InitComp();
};

Dragon :: ~Dragon(){

}
