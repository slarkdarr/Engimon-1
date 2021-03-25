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

// Excadrill::Excadrill(string nama, Engimon& other1, Engimon& other2): Engimon(nama,other1,other2){
//     InitComp();
// }

// Engimon& Excadrill ::operator=(const Engimon& a){
//     this->Engimon :: operator=(a);
//     return *this;
// }

Excadrill :: ~Excadrill(){

}