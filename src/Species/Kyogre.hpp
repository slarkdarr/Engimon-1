#ifndef KYOGRE_H
#define KYOGRE_H
	
#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Kyogre : public Engimon {
    protected:
        void InitComp();

    public :
        Kyogre();
        Kyogre(string);
        ~Kyogre();
};

#endif