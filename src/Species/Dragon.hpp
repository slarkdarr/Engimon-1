#ifndef DRAGON_HPP
#define DRAGON_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Dragon : public Engimon {
    protected:
        Element *monElements;
        Skill *monSkills;
        Engimon *monParents;
        void InitComp();

    public :
        Dragon();
        Dragon(string);
        Dragon(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Dragon();
        string getNameParent();
        ElementType getFirstElement();
        ElementType getSecondElement();
        void printInfo();
};

#endif