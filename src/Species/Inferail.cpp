#include "Inferail.hpp"  
#include "../Skill/Sunstrike.hpp"
#include "../Skill/StaticStorm.hpp"

using namespace std;

void Inferail::InitComp() {
    this->namaSpecies = "Inferail";
    monElements[0].setElement(Fire);
    monElements[1].setElement(Electric);
    this->monSkills[0] = Sunstrike();
    this->monSkills[1] = StaticStorm();
}

Inferail :: Inferail() : Engimon(){
    InitComp();
};

Inferail :: Inferail(string name) : Engimon(name){
    InitComp();
};

Inferail :: ~Inferail(){

}
