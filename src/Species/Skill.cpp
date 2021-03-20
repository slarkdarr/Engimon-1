#include <iostream>
#include "Skill.hpp"
using namespace std;


Skill::Skill() {
    this->skillName = "None";
    this->skillType = "None";
    this->basePower = 0;
    this->masteryLevel = 0;
}

Skill::Skill(string skillName) {
    this->skillName = skillName;
    this->skillType =  "Fire";
    this->basePower = 100;
    this->masteryLevel = 10;
}

Skill :: Skill(const Skill& s) {
    this->skillName = s.skillName;
    this->skillType =  s.skillType;
    this->basePower = s.basePower;
    this->masteryLevel = s.masteryLevel;
}
string Skill :: getSkillName() const{
    return this->skillName;
}

ostream& operator<<(ostream& o, const Skill& e){
    o << "Skill || Nama : " << e.skillName << " || Type :  " << e.skillType << " || basePower : " << e.basePower << " || masteryLevel : " << e.masteryLevel;
    return o;
}

bool Skill::operator==(const Skill& s) const {
    if (this->skillName == s.skillName &&
        this->skillType == s.skillType){
            return true;
        } 
    return false;
}