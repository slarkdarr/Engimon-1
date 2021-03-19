#ifndef INVENTORY_H
#define INVENTORY_H
#define MAX_CAPACITY 20
using namespace std;

#include <vector>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "Species/Skill.hpp"



template <class T>
class Inventory{

private:
    vector<T> bag;

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