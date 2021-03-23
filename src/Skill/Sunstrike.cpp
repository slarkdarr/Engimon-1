#include "Sunstrike.hpp"

Sunstrike::Sunstrike() : Skill("Sunstrike", "Fire", 150, 1) {
    this->species = "Dragon";
}

Sunstrike::Sunstrike(string species, int masteryLevel) : Skill("Sunstrike", "Fire", 150, masteryLevel) {
    this->species = species;
}
