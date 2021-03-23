#ifndef TORRENT_HPP
#define TORRENT_HPP

#include "Skill.hpp"

class Torrent : public Skill {
    private:
        string species;
    public:
        Torrent();
        Torrent(string, int);
};

#endif