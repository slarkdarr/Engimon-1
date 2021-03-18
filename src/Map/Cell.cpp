#include "Cell.hpp" 
#include "Position.hpp"
#include "../Occupier.hpp"
	
Cell::Cell()
{
	this->position = Position();
    this->cellType = Grassland_Cell;
    this->occupier = nullptr;
}
	
Cell::Cell(int x, int y, CellType cellType)
{
    this->position = Position(x,y);
    this->cellType = cellType;
    this->occupier = nullptr;
}

void Cell::setPosition(int x, int y)
{
    this->position.setPosition(x,y);
}

void Cell::setCellType(CellType cellType)
{
    this->cellType = cellType;
}

void Cell::setOccupier(Occupier* occupier)
{
    this->occupier = occupier;
}

