#ifndef FISSURE_HPP
#define FISSURE_HPP

#include "Skill.hpp"

class Fissure : public Skill {
    private:
        string species;
    public:
        Fissure();
        Fissure(string, int);
};

#endif