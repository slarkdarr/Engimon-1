#ifndef POSITION_H
#define POSITION_H

#define MAX_X 30
#define MAX_Y 20

class Position  
{
	public:
		int x,y;		
		Position();
		Position(int,int);
		static bool isValidCoordinate(int,int);
		bool setPosition(int,int);
};
#endif