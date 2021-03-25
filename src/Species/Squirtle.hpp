#ifndef SQUIRTLE_HPP
#define SQUIRTLE_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Squirtle : public Engimon {
    protected:
        void InitComp();
    public :
        Squirtle();
        Squirtle(string);
        ~Squirtle();
};

#endif