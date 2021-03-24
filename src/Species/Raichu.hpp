#ifndef RAICHU_HPP
#define RAICHU_HPP

#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Raichu : public Engimon {
    protected:
        Engimon *monParents;
        void InitComp();
    public :
        Raichu();
        Raichu(string);
        Raichu(const Raichu&);
        Raichu(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Raichu();
        string getNameParent();
        void printInfo();
};

#endif