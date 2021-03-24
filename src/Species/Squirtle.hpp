#ifndef SQUIRTLE_HPP
#define SQUIRTLE_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Squirtle : public Engimon {
    protected:
        Engimon *monParents;
        void InitComp();
    public :
        Squirtle();
        Squirtle(string);
        Squirtle(const Squirtle&);
        Squirtle(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Squirtle();
        string getNameParent();
        void printInfo();
};

#endif