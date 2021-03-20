#ifndef INVENTORY_H
#define INVENTORY_H
#define MAX_CAPACITY 6
using namespace std;
#include <vector>
#include <unordered_map>
#include "Species/Engimon.hpp"
#include "Species/Dragon.hpp"
#include "Species/Skill.hpp"



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
    void addEngimon(Engimon&);
    void removeEngimon(int);
    void addSkill(Skill&);
    void removeSkill(int);
    void printItem();
    bool isSkillExist(Skill&) const;
    bool isEmpty();
    bool isFull();
    void purgeDict();

};


#endif