#ifndef RAICHU_HPP
#define RAICHU_HPP

#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Raichu : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
        void InitComp();
    public :
        Raichu();
        Raichu(string);
        Raichu(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Raichu();
        string getNameParent();
        ElementType getFirstElement();
        ElementType getSecondElement();
        void printInfo();
};

#endif