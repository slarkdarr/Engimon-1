#ifndef ActiveEngimon_H
#define ActiveEngimon_H
#include "Species/Engimon.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Skill/Skill.hpp"
#include "Species/Squirtle.hpp"
#include "Map/Occupier.hpp"

class ActiveEngimon  : public Occupier
{
	public:
		Engimon* engimon;
		
		ActiveEngimon(Map& m, Engimon&);
		ElementType getElement1();
		ElementType getElement2();
		int getLevel();
		void setEngimon(Engimon*);
		Engimon* getEngimon();
		~ActiveEngimon();

};
#endif