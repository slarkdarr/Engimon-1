#ifndef SKILL_H
#define SKILL_H

#include <string>
using namespace std;

class Skill {
    protected:
        string skillName;
        string skillType;
        int basePower;
        int masteryLevel;

    public:
        Skill();
        Skill(string);
};

#endif