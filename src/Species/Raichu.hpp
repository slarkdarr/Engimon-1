#ifndef RAICHU_HPP
#define RAICHU_HPP

#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Raichu : public Engimon {
    protected:
        void InitComp();
    public :
        Raichu();
        Raichu(string);
        ~Raichu();

};

#endif