#include <iostream>
#include "Inventory.hpp"
#include <vector>
using namespace std;

template <class T1,class T2>
unordered_map<Skill, int, SkillHashFunction> Inventory<T1,T2>::skillDict;

template <class T1,class T2>
Inventory<T1, T2> :: Inventory() {

}

template <class T1,class T2>
Inventory<T1, T2> :: ~Inventory() {

}

template <class T1,class T2>
bool Inventory<T1, T2> :: isSkillExist(Skill& s) const{
    if(skillDict.find(s) == skillDict.end()) return false;
    return true;
}

template <class T1,class T2>
bool Inventory<T1, T2> :: isEmpty() {
    if(this->bagEngimon.empty() && this->bagSkills.empty()) return true;
    return false;
}

template <class T1,class T2>
bool Inventory<T1, T2> :: isFull(){
    if(this->bagEngimon.size() + bagSkills.size() < MAX_CAPACITY) return false;
    return true;
}

template <class T1,class T2>
void Inventory<T1,T2> :: addEngimon(Engimon& e){
    if(this->isFull()) cout << "Inventory sudah penuh" << endl;
    else{
        this->bagEngimon.push_back(e);
        cout << "Engimon berhasil dimasukkan" << endl;
    }
}

template <class T1,class T2>
void Inventory<T1, T2> :: addSkill(Skill& s){
    if(this->isFull()) cout << "Inventory sudah penuh" << endl;
    else if(this->isSkillExist(s)){
        skillDict[s]++;
    }
    else {
        skillDict[s] = 1;
        this->bagSkills.push_back(s);
        cout << "Skill berhasil dimasukkan" << endl;
    }
}

template <class T1,class T2>
void Inventory<T1, T2> :: removeSkill(int x){
    if(this->bagSkills.empty()) cout << "Tidak ada skills yang tersisa" << endl;
    else if(this->bagSkills.size() < x || x <= 0) cout << "Angka tidak valid" << endl;
    else{
        this->skillDict[bagSkills[x-1]]--;
        this->bagSkills.erase(bagSkills.begin() + (x - 1));
        cout << "Skills berhasil dihapus" << endl;
    };
}

template <class T1,class T2>
void Inventory<T1, T2> :: removeEngimon(int x){
    if(this->bagEngimon.empty()) cout << "Tidak ada engimon yang tersisa" << endl;
    else if(this->bagEngimon.size() < x || x <= 0) cout << "Angka tidak valid" << endl;
    else{
        this->bagEngimon.erase(bagEngimon.begin() + (x - 1));
        cout << "Engimon berhasil dihapus" << endl;
    };
}

// template <class T1,class T2>
// void Inventory<T1,T2> :: purgeDict() {
//     for(auto it = skillDict.begin(); it != skillDict.end(); ++it){
//         if(it->second == 0){
//             skillDict.erase(it);
//         }
//     }
// }

template <class T1,class T2>
void Inventory<T1, T2> :: printItem() {
    if(this->isEmpty()) {
        cout << "Bag kosong" << endl;
    }

    int count_skill = 0;
    for (auto i = bagSkills.begin(); i != bagSkills.end(); ++i){
        cout << count_skill + 1 << ". " << *i << " || count : " << skillDict[*i] << endl;
        count_skill++;
    }

    cout << endl;
    int count_engimon = 0;
    for (auto i = bagEngimon.begin(); i != bagEngimon.end(); ++i){
        cout << count_engimon + 1 << ". " << *i << endl;
        count_engimon++;
    }
}

template class Inventory<Skill, Engimon>;

// int main() {
//     Inventory<Skill, Engimon> *i = new Inventory<Skill, Engimon>();
//     Engimon *e1 = new Dragon("Dragon Jr");
//     Engimon *e2 = new Dragon("Dragon Jr 2");
//     Skill *s = new Skill();
//     Skill *s2 = new Skill("x2");
//     Skill *s3 = new Skill("x3");
//     i->addSkill(*s);
//     i->addSkill(*s2);
//     i->addSkill(*s3);
//     i->addEngimon(*e2);
//     i->addEngimon(*e1);
//     i->addEngimon(*e2);
//     i->printItem();
//     i->removeEngimon(2);
//     i->printItem();
//     return 0;
// }