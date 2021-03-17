#include <iostream>
#include <string>
#include "EngimonDex.h"
#include "Element.hpp"
using namespace std;

EngimonDex::EngimonDex() {
    this->monName = "";
    this->namaSpecies = NonSpecies;
    this->monElements = new Element[2];
    // tidak perlu karena default cons element adalah None
    // for (int i = 0; i < 2; i++) {
    //     this->monElements[i].setElement(ElementType::None);
    // }
}

EngimonDex& EngimonDex::operator=(const EngimonDex& other) {
    this->namaSpecies = other.namaSpecies;
    this->namaSpecies = other.namaSpecies;
    for (int i = 0; i < 2; i++) {
        this->monElements[i] = other.monElements[i];
    }
    return *this;
}