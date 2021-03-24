#include <iostream>
#include "Engimon.hpp"
#include "Dragon.hpp"

using namespace std;

void Dragon::InitComp() {
    this->namaSpecies = "Dragon";
    monElements[0].setElement(Fire);
}

Dragon :: Dragon() : Engimon(){
    InitComp();
};

Dragon :: Dragon(string name) : Engimon(name){
    InitComp();
};

Dragon::Dragon(string nama, const Engimon& other1, const Engimon& other2): Engimon(nama,other1,other2){
    InitComp();
}


// Engimon& Dragon ::operator=(const Engimon& a){
//     this->Engimon :: operator=(a);
//     return *this;
// }

Dragon :: ~Dragon(){

}
