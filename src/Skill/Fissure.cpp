#include "Fissure.hpp"

Fissure::Fissure() : Skill("Fissure", "Ground", 120, 1) {
    this->species  = "Excadrill";
}

Fissure::Fissure(string species, int masteryLevel) : Skill("Fissure", "Ground", 120, masteryLevel) {
    this->species = species;
}
