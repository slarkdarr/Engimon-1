#ifndef ENGIMON_H
#define ENGIMON_H

#include <string>
#include "../Skill/Skill.hpp"
#include "../Element.hpp"

using namespace std;

class Engimon{
private:
    void InitComp();
protected:
    int monLevel;
    int monExp;
    int monCtvExp;
    int baseLevel;
    string monName;
    string namaSpecies;
    Skill* monSkills;
    Element* monElements;
    Engimon* monParents;


    friend ostream& operator<<(ostream&, const Engimon&);

public:
    Engimon();
    Engimon(string);
    Engimon(const Engimon&);
    Engimon(string, const Engimon&, const Engimon&);
    Engimon& operator=(const Engimon&);
    void printInfo();
    void printInfoSafe();
    void printInfoSkill();
    virtual ~Engimon();
    string getName() const;
    void setName(string);
    int getLevel() const;
    void setLevel(int level);
    bool addExp(int additionalExp);
    bool isContainSkill(Skill);
    bool learnSkill(Skill);
    virtual ElementType getFirstElement() const;
    virtual ElementType getSecondElement() const;
    virtual float sumSkillPower();
    string getNamaSpecies() const;
    // string getNamaParent();
    static float maxElAdv(const Engimon* a, const Engimon* b);

};

#endif