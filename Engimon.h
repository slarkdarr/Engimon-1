#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include "EngimonDex.h"
#include "Skill.h"
using namespace std;

class Engimon{
protected:
    int monLevel;
    int monExp;
    int monCtvExp;
    string monName;
    string namaSpecies;

public:
    Engimon();
    Engimon(string);
    Engimon(string, const Engimon&, const Engimon&);
    Engimon& operator=(const Engimon&);
    void print();
    virtual ~Engimon();
    string getName() const;
    string getNamaSpecies() const;
};

#endif