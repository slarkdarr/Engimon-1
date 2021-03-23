#ifndef SUNSTRIKE_HPP
#define SUNSTRIKE_HPP

#include "Skill.hpp"

class Sunstrike : public Skill {
    private:
        string species;
    public:
        Sunstrike();
        Sunstrike(string, int);
};

#endif