#ifndef ActiveEngimon_H
#define ActiveEngimon_H
#include "Species/Engimon.hpp"
#include "Species/Articuno.hpp"
#include "Species/Dragon.hpp"
#include "Species/Excadrill.hpp"
#include "Species/Raichu.hpp"
#include "Species/Skill.hpp"
#include "Species/Squirtle.hpp"
#include "Map/Occupier.hpp"

class ActiveEngimon  : public Occupier
{
	public:
		Engimon* engimon;
		
		ActiveEngimon(Map& m, Engimon&);
		ElementType getElement();
		int getLevel();
		void setEngimon(Engimon&);
		bool setPositionOcc(int, int);
		~ActiveEngimon();

};
#endif