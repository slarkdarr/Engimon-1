#include "IceVortex.hpp"

IceVortex::IceVortex() : Skill("Ice Vortex", "Ice", 130, 1) {
    this->species = "Articuno";
}

IceVortex::IceVortex(string species, int masteryLevel) : Skill("Ice Vortex", "Ice", 130, masteryLevel) {
    this->species = species;
}
