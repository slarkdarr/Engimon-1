#include "Position.hpp"  
	
Position::Position()
{
	x = 0;
    y = 0;
}
Position::Position(int _x, int _y)
{
	x = _x;
    y = _y;
}
bool Position::setPosition(int _x, int _y)
{
    if (isValidCoordinate(x,y)){
        x = _x;
        y = _y;
        return true;
    }
    return false;
}
bool Position::isValidCoordinate(int x, int y)
{
    if (0 <= x < MAX_X && 0 <= y < MAX_Y) return true;
    return false; 
}
