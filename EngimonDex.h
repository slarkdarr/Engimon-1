#ifndef ENGIMONDEX_H
#define ENGIMONDEX_H

#include "Element.hpp"

#include <string>
using namespace std;

class EngimonDex {
    protected:
        string monName;
        string monSpecies;
        Element *monElements;
    
    public:
        EngimonDex();
        EngimonDex(string);
        EngimonDex& operator=(const EngimonDex&);
};

#endif