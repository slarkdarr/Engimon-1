#include "Torrent.hpp"

Torrent::Torrent() : Skill("Torrent", "Water", 15, 1) {
    this->species  = "Squirtle";
}

Torrent::Torrent(string species, int masteryLevel) : Skill("Torrent", "Water", 12, masteryLevel) {
    this->species = species;
}
