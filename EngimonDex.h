#ifndef ENGIMONDEX_H
#define ENGIMONDEX_H

#include <string>
using namespace std;

class EngimonDex {
    protected:
        string monName;
        string monSpecies;
        string *monElements;
    
    public:
        EngimonDex();
        EngimonDex(string);
        EngimonDex& operator=(const EngimonDex&);
};

#endif