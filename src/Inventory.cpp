#include <iostream>
#include "Inventory.hpp"
#include <vector>
using namespace std;

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
void Inventory<T1, T2> :: printItem() {
    if(this->bagSkills.empty()) cout << "Bag kosong" << endl;
    for (auto i = bagSkills.begin(); i != bagSkills.end(); ++i){
        cout << *i << endl;
    }

    for (auto i = bagEngimon.begin(); i != bagEngimon.end(); ++i){
        cout << *i << endl;
    }
}

template <class T1,class T2>
bool Inventory<T1, T2> :: isFull(){
    if(this->bagEngimon.size() + bagSkills.size() > MAX_CAPACITY) return true;
    return false;
}
int main() {
    Inventory<Skill, Engimon> *i = new Inventory<Skill, Engimon>();
    i->printItem();
    cout << i->isFull() << endl;
    return 0;
}