#ifndef INFERAIL_H
#define INFERAIL_H
	
#include <iostream>
#include "Engimon.hpp"
#include "../Element.hpp"

class Inferail : public Engimon {
    protected:
        void InitComp();

    public :
        Inferail();
        Inferail(string);
        Inferail(string, Engimon& other1, Engimon& other2);
        // Engimon& operator=(const Engimon&);
        ~Inferail();
};



#endif