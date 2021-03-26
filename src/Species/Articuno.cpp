#include <iostream>
#include "Engimon.hpp"
#include "Articuno.hpp"
#include "../Skill/IceVortex.hpp"
#include "../Skill/Magnetize.hpp"

using namespace std;

void Articuno::InitComp() {
    this->namaSpecies = "Articuno";
    monElements[0].setElement(Ice);
    this->monSkills[0] = IceVortex();
}

Articuno :: Articuno() : Engimon(){
    InitComp();
};

Articuno :: Articuno(string name) : Engimon(name){
    InitComp();
};

Articuno :: ~Articuno(){

}