#include <iostream>
#include "Engimon.hpp"
#include "Articuno.hpp"


using namespace std;


string Articuno :: getNameParent(){
    return this->monParents[0].getName();
}

ElementType Articuno :: getFirstElement(){
    return this->monElements[0].getElementType();
}

ElementType Articuno :: getSecondElement(){
    return this->monElements[1].getElementType();
}

void Articuno::InitComp() {
    this->namaSpecies = "Articuno";
    this->monElements = new Element[2];
    monElements[0].setElement(Ice);
    this->monSkills = new Skill[4];
    this->monParents = new Engimon[2];
}

Articuno :: Articuno() : Engimon(){
    InitComp();
};

Articuno :: Articuno(string name) : Engimon(name){
    InitComp();
};

Articuno :: Articuno(string name , const Engimon& parent1, const Engimon& parent2) : Engimon(name){
    InitComp();
    monParents[0] = parent1;
    monParents[1] = parent2;
}


Engimon& Articuno ::operator=(const Engimon& a){
    this->Engimon :: operator=(a);
    return *this;
}

Articuno :: ~Articuno(){
    delete[] monElements;
    delete[] monSkills;
    delete[] monParents;
}

void Articuno :: printInfo() {
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
//     Articuno *b = new Articuno("ASTAGA", a, c);
//     cout << b->getNameParent() << endl;
//     return 0;
// }