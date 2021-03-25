#include <iostream>
#include "Skill.hpp"
using namespace std;


Skill::Skill() {
    this->skillName = "None";
    this->skillType = "None";
    this->basePower = 0;
    this->masteryLevel = 0;
}

Skill::Skill(string skillName, string skillType, int basePower, int masteryLevel) {
    this->skillName = skillName;
    this->skillType = skillType;
    this->basePower = basePower;
    this->masteryLevel = masteryLevel;
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
int Skill :: getBasePower() const {
    return this->basePower;
}

void Skill::printInfo(){
    cout << "Skill " << this->skillName << ": "<< endl;
    cout << "Elemen : " << this->skillType << endl;
    cout << "Base Power : " << this->basePower << endl;
}

void Skill::printInfoAll(){
    printInfo();
    cout << "Mastery Level : " << this->masteryLevel << endl;
}

ostream& operator<<(ostream& o, const Skill& e){
    o << "Skill || Nama : " << e.skillName << " || Type :  " << e.skillType << " || basePower : " << e.basePower;
    return o;
}

bool operator==(const Skill& c1, const Skill& c2){
    return (c1.skillName == c2.skillName && c1.skillType == c2.skillType);
}
bool operator>(const Skill &c1, const Skill &c2){
    return c1.masteryLevel > c2.masteryLevel;
}
bool operator>=(const Skill &c1, const Skill &c2){
    return c1.masteryLevel >= c2.masteryLevel;
}
bool operator<(const Skill &c1, const Skill &c2){
    return !(c1 >= c2);
}
bool operator<=(const Skill &c1, const Skill &c2){
    return !(c1 > c2);;
}
bool operator!=(const Skill& c1, const Skill& c2){
    return !(c1 == c2);
}
