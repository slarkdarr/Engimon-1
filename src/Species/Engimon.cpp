#include <iostream>
#include <string>
#include "Engimon.hpp"
#include "../Skill/Skill.hpp"

using namespace std;

void Engimon::InitComp(){
    this->monName = "";
    this->namaSpecies = "";
    this->monLevel = 1;
    this->baseLevel = 1;
    this->monExp = 0;
    this->monCtvExp = 2000;
    this->monSkills = new Skill[4];
    this->monElements = new Element[2];
    this->monParents = nullptr;
}

Engimon::Engimon(){
    InitComp();
}

Engimon::Engimon(string monName){
    InitComp();
    this->monName = monName;
}

Engimon::Engimon(const Engimon& other){
    this->monName = other.monName;
    this->namaSpecies = other.namaSpecies;
    this->monLevel = other.monLevel;
    this->baseLevel = other.baseLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
    this->monSkills = new Skill[4];
    for (int i = 0; i < 4; i++) this->monSkills[i] = other.monSkills[i];
    this->monElements = new Element[2];
    this->monElements[0].setElement(other.monElements[0].getElementType());
    this->monElements[1].setElement(other.monElements[1].getElementType());
    if (other.monParents  != nullptr) {
        this->monParents = new Engimon[2];
        this->monParents[0] = other.monParents[0];
        this->monParents[1] = other.monParents[1];
    }
}


bool Engimon::isContainSkill(Skill a){
    for (int i = 0; i < 4; i++)
    {
        if (a == this->monSkills[i]) return true;
    }
    return false;
}

Engimon::Engimon(string name, Engimon& other1, Engimon& other2) {
    InitComp();
    this->monName = name;
    this->namaSpecies = "ANAK";
    this->monParents = new Engimon[2];
    this->monParents[0] = other1;
    this->monParents[1] = other2;
    other1.monLevel -= 30;
    other2.monLevel -= 30;
    
    Skill* temporaryskill = new Skill[8];
    for (int i = 0; i < 4; i++)
    {
        temporaryskill[i] = other1.monSkills[i];
        temporaryskill[i+4] = other2.monSkills[i];
    }
    for (int i = 0; i < 8; i++)
    {
        cout << temporaryskill[i] << endl;
    }
    // Sorting skill
    int i, j; 
    Skill temp;
    for (i = 0; i < 7-1; i++) {     
        for (j = 0; j < 7-i-1; j++)  {
            if (temporaryskill[j] < temporaryskill[j+1]) {
                Skill temp = temporaryskill[j]; 
                temporaryskill[j] = temporaryskill[j+1]; 
                temporaryskill[j+1] = temp; 
            }
        }
    }
    for (int i = 0; i < 8; i++)
    {
        cout << temporaryskill[i] << endl;
    }
    this->monSkills[0] = temporaryskill[0];
    cout << "berhasil" << endl;
    int angka = 1;
    for (int i = 1; i < 7; i++)
    {
        if (!isContainSkill(temporaryskill[i])) this->monSkills[angka++] = temporaryskill[i];
        if (angka == 4) break;
    }
    ElementType elbokap1 = other1.getFirstElement();
    ElementType elbokap2 = other1.getSecondElement();
    ElementType elnyokap1 = other2.getFirstElement();
    ElementType elnyokap2 = other2.getSecondElement();
    if (elbokap2 == None && elnyokap2 == None) {
        this->monElements[0].setElement(elbokap1);
        if (elbokap1 != elnyokap1){
            this->monElements[1].setElement(elnyokap1);
        }
    }
    else if (elbokap1 == elnyokap1 && elbokap2 == elnyokap2){
        this->monElements[0].setElement(elbokap1);
        this->monElements[1].setElement(elbokap2);
    }
    
    
}


void Engimon::setName(string name)
{
    this->monName = name;
}

void Engimon::setLevel(int level) {
    this->monLevel = level;
    this->baseLevel = level;
}
bool Engimon::addExp(int additionalExp) {
    int virtualExp = baseLevel * 100;
    this->monExp += additionalExp;
    std::cout << "Anda Mendapatkan " << additionalExp << " exp" << std::endl;  
    if (monExp >= monCtvExp)
    {
        delete this;
        return false;
    }
    else if (this->monLevel != ((this->monExp + virtualExp)/ 100))  {
        this->monLevel = ((this->monExp + virtualExp) / 100);
        std::cout << "LEVEL UP!! Engimon anda naik ke level " 
        << monLevel << std::endl; 
    }
    return true;
}


Engimon& Engimon::operator=(const Engimon& other){
    this->monName = other.getName();
    this->namaSpecies = other.getNamaSpecies();
    this->monLevel = other.monLevel;
    this->baseLevel = other.baseLevel;
    this->monExp = other.monExp;
    this->monCtvExp = other.monCtvExp;
    if (other.monParents) {
        this->monParents = new Engimon[2];
        this->monParents[0] = other.monParents[0];
        this->monParents[1] = other.monParents[1];
    }
    return *this;
}

string Engimon :: getNamaSpecies() const{
    return namaSpecies;
}
string Engimon :: getName() const{
    return monName;
}
int Engimon :: getLevel() const{
    return this->monLevel;
}

ElementType Engimon :: getFirstElement()
{
    return this->monElements[0].getElementType();
}

ElementType Engimon :: getSecondElement()
{
    return this->monElements[1].getElementType();
}


float Engimon :: sumSkillPower()
{
    float temp = 0;
    for (int i = 0; i < 4; i++)
    {
        temp += (this->monSkills[i].getBasePower() * this->monSkills[i].getMasteryLevel());
    }
    return temp;
}


Engimon :: ~Engimon(){

}

ostream& operator<<(ostream& os, const Engimon& e){
    os << "Engimon || Nama : " << e.getName() << " || Spesies : " << e.getNamaSpecies() << " || Level : " << e.getLevel();
    return os;
}
void Engimon::printInfo() {
    cout << "Nama : " << this->monName << endl;
    printInfoSafe();
    cout << "Exp : " << this->monExp << endl;
    cout << "Maximum Exp : " << this->monCtvExp << endl;
    cout << "List Elemen : "<< "\n";
    cout << "Elemen 1 : " << this->monElements[0].to_string() << endl;
    if(this->monElements[1].getElementType() != ElementType :: None) cout << "Elemen 2 : " << this->monElements[1].to_string() << endl;
    cout << "List skils :" << "\n";
    for (size_t i = 0; i < 4; i++)
    {
        if(this->monSkills->getSkillName() != "None"){
            cout << this->monSkills[i].getSkillName() << ", ";
        }
    }
    cout << endl;
    cout << "List nama dan spesies Parent : \n";
    if (this->monParents) {
        for (size_t j = 0; j < 2 ; j++)
        {
            cout << this->monParents[j].getName() << " Spesies : " << this->monParents[j].getNamaSpecies() << endl; 
        }
    }
}

void Engimon::printInfoSafe() {
    cout << "Nama Spesies : " << this->namaSpecies << endl;
    cout << "Level : " << this->monLevel << endl;
}

float maxFloat(float a, float b)
{
    if (a > b) return a;
    return b;
}

float Engimon::maxElAdv(Engimon* a, Engimon* b)
{
    ElementType ela1 = a->getFirstElement();
    ElementType ela2 = a->getSecondElement();
    ElementType elb1 = b->getFirstElement();
    ElementType elb2 = b->getSecondElement();

    float elAdvA[4] = 
    {
        Element::elementAdv[make_pair(ela1, elb1)],
        Element::elementAdv[make_pair(ela1, elb2)],
        Element::elementAdv[make_pair(ela2, elb2)],
        Element::elementAdv[make_pair(ela2, elb1)]
    };

    float elAdvAMax = elAdvA[0];
    for (int i = 1; i < 4; i++)
    {
        elAdvAMax = maxFloat(elAdvA[i], elAdvAMax);
    }
    return elAdvAMax;
}

// int* Engimon::quickSort(int* arr, int size) {
//     int lenLess = 0;
//     int lenMore = 0;
//     int lenPivot = 0;
//     int* less = new int[lenLess];
//     int* pivotList = new int[lenPivot];
//     int* more = new int[lenMore];
    
//     if (size <= 1) {
//         return arr;
//     }
//     else {
//         int pivot = arr[0];
//         for (int i = 0; i < size; i++) {
//             if (arr[i] < pivot) {
//                 less[lenLess++] = arr[i];
//             }
//             else if (arr[i] > pivot) {
//                 more[lenMore++] = arr[i];
//             }
//             else {
//                 pivotList[lenPivot++] = arr[i];
//             }
//         }
//         less = quickSort(less, lenLess);
//         more = quickSort(more, lenMore);
        
//         int* result = new int(lenLess+lenPivot+lenMore);
//         copy(less, less+lenLess, result);
//         copy(pivot, less+lenLess, result+lenLess);
//         copy(more, more+lenPivot, result+lenPivot);
//         return result;
//     }
// }