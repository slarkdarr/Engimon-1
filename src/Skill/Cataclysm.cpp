#include "Cataclysm.hpp"

Cataclysm::Cataclysm() : Skill("Cataclysm", "Fire", 150, 1) {
    this->species  = "None";
}

Cataclysm::Cataclysm(string species, int masteryLevel) : Skill("Cataclysm", "Fire", 180, masteryLevel) {
    this->species = species;
}
