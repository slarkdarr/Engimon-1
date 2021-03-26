#include <iostream>
#include "Engimon.hpp"
#include "Excadrill.hpp"
#include "../Skill/Fissure.hpp"

using namespace std;

void Excadrill::InitComp() {
    this->namaSpecies = "Excadrill";
    monElements[0].setElement(Ground);
    this->monSkills[0] = Fissure();
}

Excadrill :: Excadrill() : Engimon(){
    InitComp();
};

Excadrill :: Excadrill(string name) : Engimon(name){
    InitComp();
};

Excadrill :: ~Excadrill(){

}