
#ifndef ARTICUNO_HPP
#define ARTICUNO_HPP

#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"
#include "Skill.hpp"

class Articuno : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
        void InitComp();
    public :
        Articuno();
        Articuno(string);
        Articuno(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Articuno();
        string getNameParent();
        ElementType getFirstElement();
        ElementType getSecondElement();
        void printInfo();
};

#endif