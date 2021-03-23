#ifndef ICEVORTEX_HPP
#define ICEVORTEX_HPP

#include "Skill.hpp"

class IceVortex : public Skill {
    private:
        string species;
    public:
        IceVortex();
        IceVortex(string, int);
};

#endif