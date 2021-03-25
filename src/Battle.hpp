#ifndef BATTLE_HPP
#define BATTLE_HPP

#include <iostream>

#include "Element.hpp"
#include "Inventory.hpp"
#include "Player.hpp"
#include "ListEnemy.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Engimon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Skill/Skill.hpp"
#include "Species/Squirtle.hpp"
#include "Skill/Cataclysm.hpp"
#include "Skill/Fissure.hpp"
#include "Skill/IceVortex.hpp"
#include "Skill/Magnetize.hpp"
#include "Skill/Nimbus.hpp"
#include "Skill/SplinterBlast.hpp"
#include "Skill/StaticStorm.hpp"
#include "Skill/Sunstrike.hpp"
#include "Skill/Torrent.hpp"
#include "Skill/Waveform.hpp"


using namespace std;

class Battle {
    private:
        static Skill* dropRandomSkill();
    public: 
        static Player* battle(Player* myplayer, ListEnemy& musuh);
};

#endif