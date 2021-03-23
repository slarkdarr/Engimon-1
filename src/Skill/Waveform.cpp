#include "Waveform.hpp"

Waveform::Waveform() : Skill("Waveform", "Water", 170, 1) {
    this->species = "None";
}

Waveform::Waveform(string species, int masteryLevel) : Skill("Waveform", "Water", 170, masteryLevel) {
    this->species = species;
}
