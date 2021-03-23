#ifndef SPLINTERBLAST_HPP
#define SPLINTERBLAST_HPP

#include "Skill.hpp"

class SplinterBlast : public Skill {
    private:
        string species;
    public:
        SplinterBlast();
        SplinterBlast(string, int);
};

#endif