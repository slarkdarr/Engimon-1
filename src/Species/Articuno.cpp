#include <iostream>
#include "Engimon.hpp"
#include "Articuno.hpp"

using namespace std;

void Articuno::InitComp() {
    this->namaSpecies = "Articuno";
    monElements[0].setElement(Ice);
}

Articuno :: Articuno() : Engimon(){
    InitComp();
};

Articuno :: Articuno(string name) : Engimon(name){
    InitComp();
};

Articuno::Articuno(string nama, const Engimon& other1, const Engimon& other2): Engimon(nama,other1,other2){
    InitComp();
}

// Engimon& Articuno ::operator=(const Engimon& a){
//     this->Engimon :: operator=(a);
//     return *this;
// }

Articuno :: ~Articuno(){

}