#ifndef MAGNETIZE_HPP
#define MAGNETIZE_HPP

#include "Skill.hpp"

class Magnetize : public Skill {
    private:
        string species;
    public:
        Magnetize();
        Magnetize(string, int);
};

#endif