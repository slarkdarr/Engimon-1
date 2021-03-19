#include <iostream>
#include "Inventory.hpp"
#include <vector>
using namespace std;

template<class T>
Inventory<T> :: Inventory() {
    Skill *e = new Skill("x"); 
    this->bag.push_back(*e);
}

template<class T>
Inventory<T> :: ~Inventory() {

}

template<class T>
void Inventory<T> :: printItem() {
    if(this->bag.empty()) cout << "Bag kosong" << endl;
    for (auto i = bag.begin(); i != bag.end(); ++i){
        cout << *i << endl;
    }
}

template<class T>
void Inventory<T> :: addEnigmon(Engimon& e){
    
}
int main() {
    Inventory<Skill> *i = new Inventory<Skill>();
    i->printItem();
    return 0;
}