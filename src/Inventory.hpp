#ifndef INVENTORY_H
#define INVENTORY_H
#define MAX_CAPACITY 6
using namespace std;
#include <vector>
#include <unordered_map>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "Skill/Skill.hpp"
#include "Bag.hpp"

template <class T>
class Bag;

template <class T1,class T2>
class Inventory{

private:
    vector<T1> bagSkills;
    vector<T2> bagEngimon;
    // typedef unordered_map<Skill, int, SkillHashFunction> umapSkill;
    static unordered_map<Skill, int, SkillHashFunction> skillDict;

public:
    Inventory();
    ~Inventory();
    bool addEngimon(const Engimon&);
    void removeEngimon(int);
    void addSkill(Skill&);
    void removeSkill(int);
    void printItem();
    void printAllEngimonInfo();
    void printAllSkillInfo();
    bool isSkillExist(Skill&) const;
    bool isEmpty();
    bool isEngimonBagEmpty();
    int EngimonBagSize();
    bool isBagSkillsEmpty();
    Bag<Engimon>* listEngimon();
    Bag<Skill>* listSkill();
    bool isFull();
    // void purgeDict();

};


#endif