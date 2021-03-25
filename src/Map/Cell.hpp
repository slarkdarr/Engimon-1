#ifndef CELL_H
#define CELL_H

#include "Position.hpp"
#include "Occupier.hpp"

enum CellType {
	Sea_Cell,
	Grassland_Cell,
	Rancu
};

class Occupier;

class Cell  
{
	public:
		Position position;
		CellType cellType;
		Occupier* occupier;
		Cell();
		Cell(int x, int y, CellType);
		void setPosition(int _x,int _y);
		void setCellType(CellType);
		void setOccupier(Occupier*);

};
#endif