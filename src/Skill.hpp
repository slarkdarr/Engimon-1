#ifndef _SKILL_HPP_
#define _SKILL_HPP_

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