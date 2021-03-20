#include <iostream>
#include "Engimon.hpp"
#include "Dragon.hpp"
#include "Skill.hpp"

using namespace std;


string Dragon :: getNameParent(){
    return this->monParents[0].getName();
}

ElementType Dragon :: getFirstElement(){
    return this->monElements[0].getElementType();
}

void Dragon::InitComp() {
    this->namaSpecies = "Dragon";
    this->monElements = new Element[2];
    monElements[0].setElement(Fire);
    this->monSkills = new Skill[4];
    this->monParents = new Engimon[2];
}

Dragon :: Dragon() : Engimon(){
    InitComp();
};

Dragon :: Dragon(string name) : Engimon(name){
    InitComp();
};

Dragon :: Dragon(string name , const Engimon& parent1, const Engimon& parent2) : Engimon(name){
    InitComp();
    monParents[0] = parent1;
    monParents[1] = parent2;
}

Engimon& Dragon ::operator=(const Engimon& a){
    this->Engimon :: operator=(a);
    return *this;
}

Dragon :: ~Dragon(){
    delete[] monElements;
    delete[] monSkills;
    delete[] monParents;
}

void Dragon :: printInfo() {
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
//     Dragon *b = new Dragon("ASTAGA", a, c);
//     cout << b->getNameParent() << endl;
//     return 0;
// }