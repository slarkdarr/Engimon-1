#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>

// #include "EngimonDex.hpp"
#include "Element.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Engimon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Species/Skill.hpp"
#include "Species/Squirtle.hpp"

using namespace std;

class Battle {
    private:
        Player player;
        Engimon e1;
        Engimon e2;
    public:
        Battle();
        Battle(Player player, Engimon e1, Engimon e2);
};

#endif