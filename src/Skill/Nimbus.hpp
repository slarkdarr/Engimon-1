#ifndef NIMBUS_HPP
#define NIMBUS_HPP

#include "Skill.hpp"

class Nimbus : public Skill {
    private:
        string species;
    public:
        Nimbus();
        Nimbus(string, int);
};

#endif