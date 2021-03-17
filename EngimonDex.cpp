#include <iostream>
#include <string>
#include "EngimonDex.h"
using namespace std;

EngimonDex::EngimonDex() {
    this->monName = "None";
    this->monSpecies = "None";
    this->monElements = new Element[2];
    // tidak perlu karena default cons element adalah None
    // for (int i = 0; i < 2; i++) {
    //     this->monElements[i].setElement(ElementType::None);
    // }
}

EngimonDex::EngimonDex(string monName) {
    this->monName = monName;
    this->monElements = new Element[2];
    if (monName == "Charizard") {
        this->monSpecies = "Dragon";
        this->monElements[0].setElement(ElementType::Fire);

    } else if (monName == "Blastoise") {
        this->monSpecies = "Tortoise";
        this->monElements[0].setElement(Water);

    } else if (monName == "Raichu") {
        this->monSpecies = "Mouse";
        this->monElements[0].setElement(Electric);

    } else if (monName == "Hippowdon") {
        this->monSpecies = "Hippo";
        this->monElements[0].setElement(Ground);

    } else if (monName == "Beartic") {
        this->monSpecies = "Bear";
        this->monElements[0].setElement(Ice);

    } else if (monName == "Walrein") {
        this->monSpecies = "Walrus";
        this->monElements[0].setElement(Water);
        this->monElements[1].setElement(Ice);
    } else if (monName == "Gastrodon") {
        this->monSpecies = "Snail";
        this->monElements[0].setElement(Water);
        this->monElements[1].setElement(Ground);
    } else if (monName == "Rotom") {
        this->monSpecies = "Spirit";
        this->monElements[0].setElement(Fire);
        this->monElements[1].setElement(Electric);
    }
}

EngimonDex& EngimonDex::operator=(const EngimonDex& other) {
    this->monName = other.monName;
    this->monSpecies = other.monSpecies;
    for (int i = 0; i < 2; i++) {
        this->monElements[i] = other.monElements[i];
    }
}