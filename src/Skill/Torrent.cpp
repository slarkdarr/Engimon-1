#include "Torrent.hpp"

Torrent::Torrent() : Skill("Torrent", "Water", 110, 1) {
    this->species  = "Squirtle";
}

Torrent::Torrent(string species, int masteryLevel) : Skill("Torrent", "Water", 120, masteryLevel) {
    this->species = species;
}
