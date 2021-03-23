#ifndef WAVEFORM_HPP
#define WAVEFORM_HPP

#include "Skill.hpp"

class Waveform : public Skill {
    private:
        string species;
    public:
        Waveform();
        Waveform(string, int);
};

#endif