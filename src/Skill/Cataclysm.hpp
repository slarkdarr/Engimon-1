#ifndef CATACLYSM_HPP
#define CATACLYSM_HPP

#include "Skill.hpp"

class Cataclysm : public Skill {
    private:
        string species;
    public:
        Cataclysm();
        Cataclysm(string, int);
};

#endif