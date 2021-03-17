#include <iostream>
#include <string>
#include "Skill.h"
using namespace std;

Skill::Skill() {
    this->skillName = "None";
    this->skillType = "None";
    this->basePower = 0;
    this->masteryLevel = 0;
}

Skill::Skill(string skillName) {
    this->skillName = skillName;
    this->skillType = "Fire";
    this->basePower = 100;
    this->masteryLevel = 10;
}
