#include "Waveform.hpp"

Waveform::Waveform() : Skill("Waveform", "Water", 17, 1) {
    this->species = "None";
}

Waveform::Waveform(string species, int masteryLevel) : Skill("Waveform", "Water", 17, masteryLevel) {
    this->species = species;
}
