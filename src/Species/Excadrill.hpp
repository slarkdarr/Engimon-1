#ifndef EXCADRILL_HPP
#define EXCADRILL_HPP


#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"


class Excadrill : public Engimon {
    protected:
        void InitComp();
    public :
        Excadrill();
        Excadrill(string);
        Excadrill(string nama, const Engimon& other1, const Engimon& other2);
        // Engimon& operator=(const Engimon&);
        ~Excadrill();
};

#endif