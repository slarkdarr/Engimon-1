#ifndef SEISMOTOAD_H
#define SEISMOTOAD_H
	
#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Seismotoad : public Engimon {
    protected:
        void InitComp();

    public :
        Seismotoad();
        Seismotoad(string);
        ~Seismotoad();
};

#endif