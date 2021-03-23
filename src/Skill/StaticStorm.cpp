#include "StaticStorm.hpp"

StaticStorm::StaticStorm() : Skill("Static Storm", "Electric", 140, 1) {
    this->species  = "Raichu";
}

StaticStorm::StaticStorm(string species, int masteryLevel) : Skill("Static Storm", "Electric", 140, masteryLevel) {
    this->species = species;
}
