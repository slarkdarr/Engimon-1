#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include "Skill.hpp"
#include "../Element.hpp"
using namespace std;

class Engimon{
protected:
    int monLevel;
    int monExp;
    int monCtvExp;
    string monName;
    string namaSpecies;
    friend ostream& operator<<(ostream&, const Engimon&);

public:
    Engimon();
    Engimon(string);
    // Engimon(string, const Engimon&, const Engimon&);
    Engimon& operator=(const Engimon&);
    void printInfo();
    virtual ~Engimon();
    string getName() const;
    int getLevel() const;
    virtual ElementType getFirstElement();
    string getNamaSpecies() const;
};

#endif