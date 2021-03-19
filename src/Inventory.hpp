#ifndef INVENTORY_H
#define INVENTORY_H
#define MAX_CAPACITY 5
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
    void addEngimon(Engimon&);
    void removeEngimon(int);
    void addSkill(Skill&);
    void removeSkill(int);
    void printItem();
    bool isSkillExist(Skill&);
    bool isEmpty();
    bool isFull();
    

};

#endif