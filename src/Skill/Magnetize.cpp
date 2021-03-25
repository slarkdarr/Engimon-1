#include "Magnetize.hpp"

Magnetize::Magnetize() : Skill("Magnetize", "Ground", 15, 1) {
    this->species = "Excadrill";
}

Magnetize::Magnetize(string species, int masteryLevel) : Skill("Magnetize", "Ground", 15, masteryLevel) {
    this->species = species;
}
