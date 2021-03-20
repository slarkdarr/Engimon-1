#ifndef EXCADRILL_HPP
#define EXCADRILL_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"
#include "Skill.hpp"

class Excadrill : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
        void InitComp();
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

#endif