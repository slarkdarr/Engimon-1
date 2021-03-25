#include "Sunstrike.hpp"

Sunstrike::Sunstrike() : Skill("Sunstrike", "Fire", 15, 1) {
    this->species = "Dragon";
}

Sunstrike::Sunstrike(string species, int masteryLevel) : Skill("Sunstrike", "Fire", 15, masteryLevel) {
    this->species = species;
}
