#include <iostream>
#include <string>
#include "EngimonDex.h"
using namespace std;

EngimonDex::EngimonDex() {
    this->monName = "None";
    this->monSpecies = "None";
    this->monElements = new string[2];
    for (int i = 0; i < 2; i++) {
        this->monElements[i] = "None";
    }
}

EngimonDex::EngimonDex(string monName) {
    this->monName = monName;
    this->monElements = new string[2];
    if (monName == "Charizard") {
        this->monSpecies = "Dragon";
        this->monElements[0] = "Fire";
        this->monElements[1] = "None";
    } else if (monName == "Blastoise") {
        this->monSpecies = "Tortoise";
        this->monElements[0] = "Water";
        this->monElements[1] = "None";
    } else if (monName == "Raichu") {
        this->monSpecies = "Mouse";
        this->monElements[0] = "Electric";
        this->monElements[1] = "None";
    } else if (monName == "Hippowdon") {
        this->monSpecies = "Hippo";
        this->monElements[0] = "Ground";
        this->monElements[1] = "None";
    } else if (monName == "Beartic") {
        this->monSpecies = "Bear";
        this->monElements[0] = "Ice";
        this->monElements[1] = "None";
    } else if (monName == "Walrein") {
        this->monSpecies = "Walrus";
        this->monElements[0] = "Water";
        this->monElements[1] = "Ice";
    } else if (monName == "Gastrodon") {
        this->monSpecies = "Snail";
        this->monElements[0] = "Water";
        this->monElements[1] = "Ground";
    } else if (monName == "Rotom") {
        this->monSpecies = "Spirit";
        this->monElements[0] = "Fire";
        this->monElements[1] = "Electric";
    }
}

EngimonDex& EngimonDex::operator=(const EngimonDex& other) {
    this->monName = other.monName;
    this->monSpecies = other.monSpecies;
    for (int i = 0; i < 2; i++) {
        this->monElements[i] = other.monElements[i];
    }
}