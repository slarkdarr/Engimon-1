#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"
#include "Skill.hpp"

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
    void printInfo();
};