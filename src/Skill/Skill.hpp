#ifndef _SKILL_HPP_
#define _SKILL_HPP_

#include <string>
using namespace std;

class Skill {
    protected:
        int basePower;
        int masteryLevel;
        friend ostream& operator<<(ostream& os, const Skill& s);
    public:
        string skillName;
        string skillType;
        Skill();
        Skill(string);
        Skill(const Skill&);
        string getSkillName() const;
        bool operator==(const Skill&) const ;
};

class SkillHashFunction{
public:
    size_t operator()(const Skill& s) const
    {
        return s.skillName.length() + s.skillType.length();
    }
};
#endif