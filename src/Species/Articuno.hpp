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
        Articuno(string nama, const Engimon& other1, const Engimon& other2);
        // Engimon& operator=(const Engimon&);
        ~Articuno();
};

#endif