#ifndef DRAGON_HPP
#define DRAGON_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Dragon : public Engimon {
    protected:
        void InitComp();

    public :
        Dragon();
        Dragon(string);
        ~Dragon();
};

#endif