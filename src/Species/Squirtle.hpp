#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"
#include "Skill.hpp"

class Squirtle : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
    public :
        Squirtle();
        Squirtle(string);
        Squirtle(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Squirtle();
        string getNameParent();
        ElementType getFirstElement();
        void printInfo();
};