#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"
#include "Skill.hpp"

class Excadrill : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
    public :
        Excadrill();
        Excadrill(string);
        Excadrill(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Excadrill();
        string getNameParent();
        ElementType getFirstElement();
        void printInfo();
};