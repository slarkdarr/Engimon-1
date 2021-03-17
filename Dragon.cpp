#include<iostream>
#include "Engimon.h"
#include "Engimon.cpp"
#include "Element.cpp"
#include "Element.hpp"
#include "Skill.h"
#include "Skill.cpp"
using namespace std;
class Dragon : public Engimon {
protected:
    Element *monElements;
    Skill *monSkills;
    Engimon *monParents;
public :
    Dragon();
    Dragon(string);
    Dragon(string, const Engimon&, const Engimon&);
    Engimon& operator=(const Engimon&);
    ~Dragon();
    string getNameParent();
};

string Dragon :: getNameParent(){
    return this->monParents[0].getName();
}
Dragon :: Dragon() : Engimon(){
    this->monName = "";
    this->namaSpecies = "Dragon";
    this->monElements = new Element[2];
    monElements[0].setElement(Fire);
    this->monSkills = new Skill[4];
    this->monParents = new Engimon[4];
};

Dragon :: Dragon(string name) : Engimon(){
    this->monName = name;
    this->namaSpecies = "Dragon";
    this->monElements = new Element[2];
    monElements[0].setElement(Fire);
    this->monSkills = new Skill[4];
    this->monParents = new Engimon[4];
};

Engimon& Dragon ::operator=(const Engimon& a){
    this->Engimon :: operator=(a);
    return *this;
}
Dragon :: Dragon(string name , const Engimon& parent1, const Engimon& parent2){
    this->monName = name;
    this->namaSpecies = "Dragon";
    this->monElements = new Element[2];
    monElements[0].setElement(Fire);
    this->monSkills = new Skill[4];
    this->monParents = new Engimon[2];
    monParents[0] = parent1;
    monParents[1] = parent2;
}
Dragon :: ~Dragon(){
    delete monElements;
    delete monSkills;
    delete monParents;
}

int main() {
    Engimon a("bapak"), c("ibu");
    Dragon *b = new Dragon("ASTAGA", a, c);
    cout << b->getNameParent() << endl;
    return 0;
}