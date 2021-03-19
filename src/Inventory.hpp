#ifndef INVENTORY_H
#define INVENTORY_H
#define MAX_CAPACITY 20
using namespace std;

#include <vector>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "Species/Skill.hpp"



template <class T1,class T2>
class Inventory{

private:
    vector<T1> bagSkills;
    vector<T2> bagEngimon;

public:
    Inventory();
    ~Inventory();
    void addEnigmon(Engimon&);
    void removeItem(int);
    bool isSkillExist(Skill&);
    void addSkill(Skill&);
    bool isFull();
    void printItem();

};

#endif