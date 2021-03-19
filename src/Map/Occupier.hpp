#ifndef OCCUPIER_H
#define OCCUPIER_H
class Map;
#include "Map.hpp"
// ABSTRACT CLASS OCCUPIER ADALAH PARENT CLASS DARI ENEMY DAN PLAYER
#include "Position.hpp"
#include "Cell.hpp"


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
		Map* m;
		
	public:
		Occupier_Type ocpType;
		Occupier(Map& m);
		Occupier(Map& m,int, int, Occupier_Type);
		virtual ~Occupier();
		Position getPosition();
		virtual int getLevel() = 0;
		virtual bool setPositionOcc(int, int);
		// virtual void move(char c);
		void printPosition();
};
#endif