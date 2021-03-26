#include <iostream>
#include "Engimon.hpp"
#include "Squirtle.hpp"
#include "../Skill/Torrent.hpp"

using namespace std;

void Squirtle::InitComp() {
    this->namaSpecies = "Squirtle";
    this->monElements[0].setElement(Water);
    this->monSkills[0] = Torrent();
}

Squirtle :: Squirtle() : Engimon(){
    InitComp();
};

Squirtle :: Squirtle(string name) : Engimon(name){
    InitComp();
};

Squirtle :: ~Squirtle(){

}