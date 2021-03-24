#include <iostream>
#include "Engimon.hpp"
#include "Raichu.hpp"

using namespace std;

void Raichu::InitComp() {
    this->namaSpecies = "Raichu";
    monElements[0].setElement(Electric);

}

Raichu :: Raichu() : Engimon(){
    InitComp();
};

Raichu :: Raichu(string name) : Engimon(name){
    InitComp();
};

Raichu::Raichu(string nama, const Engimon& other1, const Engimon& other2): Engimon(nama,other1,other2){
    InitComp();
}

// Engimon& Raichu ::operator=(const Engimon& a){
//     this->Engimon :: operator=(a);
//     return *this;
// }

Raichu :: ~Raichu(){

}
