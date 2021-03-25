#ifndef ARTICUNO_HPP
#define ARTICUNO_HPP

#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Articuno : public Engimon {
    protected:
        void InitComp();
    public :
        Articuno();
        Articuno(string);
        ~Articuno();
};

#endif