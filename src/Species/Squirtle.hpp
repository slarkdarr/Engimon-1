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
        Squirtle(string nama, const Engimon& other1, const Engimon& other2);
        // Engimon& operator=(const Engimon&);
        ~Squirtle();
};

#endif