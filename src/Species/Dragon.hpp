#ifndef DRAGON_HPP
#define DRAGON_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Dragon : public Engimon {
    protected:
        Engimon *monParents;
        void InitComp();

    public :
        Dragon();
        Dragon(string);
        Dragon(const Dragon&);
        Dragon(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Dragon();
        string getNameParent();
        void printInfo();
};

#endif