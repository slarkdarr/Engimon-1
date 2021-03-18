#ifndef OCCUPIER_H
#define OCCUPIER_H

// ABSTRACT CLASS OCCUPIER ADALAH PARENT CLASS DARI ENEMY DAN PLAYER

#include "Map/Position.hpp"
enum Occupier_Type {
	Player_Type,
	F,
	W,
	E,
	G,
	I,
	Unknown
};

class Occupier  
{
	protected:
		Position position;
		int level;
	public:
		Occupier_Type ocpType;
		Occupier();
		Occupier(int, int, int,Occupier_Type);
		Position getPosition();
		int getLevel();
		virtual bool setPosition(int,int);
		void printPosition();
};
#endif