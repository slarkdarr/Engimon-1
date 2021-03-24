#ifndef EXCADRILL_HPP
#define EXCADRILL_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Excadrill : public Engimon {
    protected:
        Engimon *monParents;
        void InitComp();
    public :
        Excadrill();
        Excadrill(string);
        Excadrill(const Excadrill&);
        Excadrill(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        ~Excadrill();
        string getNameParent();
        void printInfo();
};

#endif