#include "Cataclysm.hpp"

Cataclysm::Cataclysm() : Skill("Cataclysm", "Fire", 15, 1) {
    this->species  = "None";
}

Cataclysm::Cataclysm(string species, int masteryLevel) : Skill("Cataclysm", "Fire", 18, masteryLevel) {
    this->species = species;
}
