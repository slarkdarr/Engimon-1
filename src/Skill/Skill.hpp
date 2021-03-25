#ifndef _SKILL_HPP_
#define _SKILL_HPP_

#include <string>
using namespace std;

class Skill {
    protected:
        int basePower;
        
        friend ostream& operator<<(ostream& os, const Skill& s);
    public:
        int masteryLevel;
        string skillName;
        string skillType;
        Skill();
        Skill(string, string, int, int);
        Skill(const Skill&);
        string getSkillName() const;
        int getBasePower() const;
        void printInfo();
        void printInfoAll();
        friend bool operator==(const Skill& c1, const Skill& c2);
        friend bool operator!=(const Skill& c1, const Skill& c2);
        friend bool operator>(const Skill &c1, const Skill &c2);
        friend bool operator<(const Skill &c1, const Skill &c2);
	    friend bool operator>=(const Skill &c1, const Skill &c2);
        friend bool operator!=(const Skill& c1, const Skill& c2);
};

class SkillHashFunction{
public:
    size_t operator()(const Skill& s) const
    {
        return s.skillName.length() + s.skillType.length();
    }
};
#endif