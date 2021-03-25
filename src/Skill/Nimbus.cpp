#include "Nimbus.hpp"

Nimbus::Nimbus() : Skill("Nimbus", "Electric", 16, 1) {
    this->species = "None";
}

Nimbus::Nimbus(string species, int masteryLevel) : Skill("Nimbus", "Electric", 16, masteryLevel) {
    this->species = species;
}
