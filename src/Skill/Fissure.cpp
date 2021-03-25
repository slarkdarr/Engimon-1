#include "Fissure.hpp"

Fissure::Fissure() : Skill("Fissure", "Ground", 12, 1) {
    this->species  = "Excadrill";
}

Fissure::Fissure(string species, int masteryLevel) : Skill("Fissure", "Ground", 12, masteryLevel) {
    this->species = species;
}
