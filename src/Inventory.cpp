#include <iostream>
#include "Inventory.hpp"
#include <vector>
using namespace std;
//if(this->bagEngimon.empty() && this->bagSkills.empty())
template <class T1,class T2>
Inventory<T1, T2> :: Inventory() {
    Skill *e = new Skill("x"); 
    this->bagSkills.push_back(*e);
    Engimon *g = new Dragon("x");
    this->bagEngimon.push_back(*g);
}

template <class T1,class T2>
Inventory<T1, T2> :: ~Inventory() {

}

template <class T1,class T2>
bool Inventory<T1, T2> :: isEmpty() {
    if(this->bagEngimon.empty() && this->bagSkills.empty()) return true;
    return false;
}

template <class T1,class T2>
void Inventory<T1, T2> :: printItem() {
    if(this->isEmpty()) cout << "Bag kosong" << endl;
    int count = 0;
    for (auto i = bagSkills.begin(); i != bagSkills.end(); ++i){
        cout << count + 1 << ". " << *i << endl;
        count++;
    }

    for (auto i = bagEngimon.begin(); i != bagEngimon.end(); ++i){
        cout << count + 1 << ". " << *i << endl;
        count++;
    }
}

template <class T1,class T2>
bool Inventory<T1, T2> :: isFull(){
    if(this->bagEngimon.size() + bagSkills.size() >= MAX_CAPACITY) return true;
    return false;
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
bool Inventory<T1, T2> ::isSkillExist(Skill& s){
    for(auto s : this->bagSkills){

    }
    return false;
}

template <class T1,class T2>
void Inventory<T1, T2> :: addSkill(Skill& s){
    if(this->isSkillExist(s)) cout << "Skill item sudah ada di dalam inventory" << endl;
    else if(this->isFull()) cout << "Inventory sudah penuh" << endl;
    else {
        this->bagSkills.push_back(s);
        cout << "Skill berhasil dimasukkan" << endl;
    }
}

template <class T1,class T2>
void Inventory<T1, T2> :: removeEngimon(int x){
    if(this->bagEngimon.empty()) cout << "Tidak ada engimon yang tersisa" << endl;
    else if(this->bagEngimon.size() < x || x <= 0) cout << "Angka tidak valid" << endl;
    else{
        this->bagEngimon.erase(bagEngimon.begin() + (x - 1));
        cout << "Engimon berhasil dihapus" << endl;
    } ;
}

template <class T1,class T2>
void Inventory<T1, T2> :: removeSkill(int x){
    if(this->bagSkills.empty()) cout << "Tidak ada skills yang tersisa" << endl;
    else if(this->bagSkills.size() < x || x <= 0) cout << "Angka tidak valid" << endl;
    else{
        this->bagSkills.erase(bagSkills.begin() + (x - 1));
        cout << "Skills berhasil dihapus" << endl;
    };
}

int main() {
    Inventory<Skill, Engimon> *i = new Inventory<Skill, Engimon>();
    Engimon *dr = new Dragon("Dragon Jr");
    Skill *s = new Skill();
    i->addSkill(*s);
    i->addSkill(*s);
    i->removeEngimon(1);
    i->removeSkill(1);
    i->removeSkill(1);
    i->removeSkill(1);
    i->printItem();
    return 0;
}