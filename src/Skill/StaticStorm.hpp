#ifndef STATICSTORM_HPP
#define STATICSTORM_HPP

#include "Skill.hpp"

class StaticStorm : public Skill {
    private:
        string species;
    public:
        StaticStorm();
        StaticStorm(string, int);
};

#endif