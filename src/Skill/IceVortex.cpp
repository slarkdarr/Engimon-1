#include "IceVortex.hpp"

IceVortex::IceVortex() : Skill("Ice Vortex", "Ice", 13, 1) {
    this->species = "Articuno";
}

IceVortex::IceVortex(string species, int masteryLevel) : Skill("Ice Vortex", "Ice", 13, masteryLevel) {
    this->species = species;
}
