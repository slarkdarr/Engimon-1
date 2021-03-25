#include "SplinterBlast.hpp"

SplinterBlast::SplinterBlast() : Skill("Splinter Blast", "Ice", 16, 1) {
    this->species = "None";
}

SplinterBlast::SplinterBlast(string species, int masteryLevel) : Skill("Splinter Blast", "Ice", 16, masteryLevel) {
    this->species = species;
}
