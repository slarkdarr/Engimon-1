#include "StaticStorm.hpp"

StaticStorm::StaticStorm() : Skill("Static Storm", "Electric", 14, 1) {
    this->species  = "Raichu";
}

StaticStorm::StaticStorm(string species, int masteryLevel) : Skill("Static Storm", "Electric", 14, masteryLevel) {
    this->species = species;
}
