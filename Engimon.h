#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include "EngimonDex.h"
#include "Skill.h"
using namespace std;

class Engimon: public EngimonDex {
    protected:
        EngimonDex *monParents;
        Skill *monSkills;
        int monLevel;
        int monExp;
        int monCtvExp;

    public:
        Engimon();
        Engimon(string);
        Engimon(string, const Engimon&, const Engimon&);
        Engimon& operator=(const Engimon&);
        void print();
};

#endif