#include <iostream>
#include "Engimon.hpp"
#include "Squirtle.hpp"


using namespace std;


string Squirtle :: getNameParent(){
    return this->monParents[0].getName();
}

void Squirtle::InitComp() {
    this->namaSpecies = "Squirtle";
    this->monElements[0].setElement(Water);
    this->monParents = new Engimon[2];
}

Squirtle :: Squirtle() : Engimon(){
    InitComp();
};

Squirtle :: Squirtle(string name) : Engimon(name){
    InitComp();
};

Squirtle::Squirtle(const Squirtle& other) : Engimon(other) {
    this->monParents = new Engimon[2];
    monParents[0] = other.monParents[0];
    monParents[1] = other.monParents[1];
}

Squirtle :: Squirtle(string name , const Engimon& parent1, const Engimon& parent2) : Engimon(name){
    InitComp();
    monParents[0] = parent1;
    monParents[1] = parent2;
}


Engimon& Squirtle ::operator=(const Engimon& a){
    this->Engimon :: operator=(a);
    return *this;
}

Squirtle :: ~Squirtle(){
    delete[] monElements;
    delete[] monSkills;
    delete[] monParents;
}

void Squirtle :: printInfo() {
    Engimon :: printInfo();
    cout << "List Elemen : "<< "\n";
    cout << "Elemen 1 : " << this->monElements[0].to_string() << endl;
    if(this->monElements[1].getElementType() != ElementType :: None) cout << "Elemen 2 : " << this->monElements[1].to_string() << endl;
    cout << "List skils :" << "\n";
    for (size_t i = 0; i < 4; i++)
    {
        if(this->monSkills->getSkillName() != "None"){
            cout << this->monSkills[i].getSkillName() << ", ";
        }
    }
    cout << endl;
    cout << "List nama dan spesies Parent : \n";
    for (size_t j = 0; j < 2 ; j++)
    {
          cout << this->monParents[j].getName() << " Spesies : " << this->monParents[j].getNamaSpecies() << endl; 
    }
}

// int main() {
//     Engimon a("bapak"), c("ibu");
//     Squirtle *b = new Squirtle("ASTAGA", a, c);
//     cout << b->getNameParent() << endl;
//     return 0;
// }