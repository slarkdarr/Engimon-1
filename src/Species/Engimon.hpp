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
    Engimon(string, Engimon&, Engimon&);
    Engimon& operator=(const Engimon&);
    void printInfo();
    void printInfoSafe();
    virtual ~Engimon();
    string getName() const;
    void setName(string);
    int getLevel() const;
    void setLevel(int level);
    bool addExp(int additionalExp);
    bool isContainSkill(Skill);
    virtual ElementType getFirstElement();
    virtual ElementType getSecondElement();
    virtual float sumSkillPower();
    string getNamaSpecies() const;
    // string getNamaParent();
    static float maxElAdv(Engimon* a, Engimon* b);
    int* quickSort(int*, int);

};

#endif