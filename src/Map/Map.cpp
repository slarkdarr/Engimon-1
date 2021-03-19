#include "Map.hpp"  
#include "Cell.hpp"
#include <iostream>

Map::Map()
{
	this->cells = new Cell[MAX_X * MAX_Y];
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        this->cells[i].setPosition(i % MAX_X, i / MAX_X);
    }
}
	
Map::~Map()
{
	delete[] cells;
}

void Map::createGrassland()
{
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        this->cells[i].setCellType(Grassland_Cell);
    }
}

// Membuat Sea sesuai luas MAX_Y * MAX_X
void Map::createSea()
{
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        this->cells[i].setCellType(Sea_Cell);
    }
}

// Membuat Grassland sesuai area, mereturn true jika berhasil
void Map::setGrassland(int x_kiri, int x_kanan, int y_kiri, int y_kanan)
{
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        int x = i % MAX_X;
        int y = i / MAX_X;
        if (x >= x_kiri && x <= x_kanan && y >= y_kiri && y <= y_kanan) 
        {
            this->cells[i].setCellType(Grassland_Cell);
        } 
    }
}

// Membuat Grassland sesuai area, mereturn true jika gagal
void Map::setSea(int x_kiri, int x_kanan, int y_kiri, int y_kanan)
{
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        int x = i % MAX_X;
        int y = i / MAX_X;
        if (x >= x_kiri && x <= x_kanan && y >= y_kiri && y <= y_kanan) 
        {
            this->cells[i].setCellType(Sea_Cell);
        } 
    }
}

void Map::printMap(int currentlevel)
{
    char mapTemp[MAX_X][MAX_Y]{}; 
    for (int i = 0; i < MAX_X * MAX_Y; i++)
    {
        int x = i % MAX_X;
        int y = i / MAX_X;
        // Jika ada Occupier
        if (this->cells[i].occupier)
        {
            switch (this->cells[i].occupier->ocpType)
            {
            case Player_Type:
                mapTemp[x][y] = 'P';
                break;
            case Enemy_Type:
                switch (cells[i].occupier->getElement())
                {
                case Fire:
                    mapTemp[x][y] = (cells[i].occupier->getLevel() < currentlevel) ? 'F' : 'f';
                    break;
                case Water:
                    mapTemp[x][y] = (cells[i].occupier->getLevel() < currentlevel) ? 'W' : 'w';
                    break;
                case Electric:
                    mapTemp[x][y] = (cells[i].occupier->getLevel() < currentlevel) ? 'E' : 'e';
                    break;
                case Ground:
                    mapTemp[x][y] = (cells[i].occupier->getLevel() < currentlevel) ? 'G' : 'g';
                    break;
                case Ice:
                    mapTemp[x][y] = (cells[i].occupier->getLevel() < currentlevel) ? 'I' : 'i';
                    break;
                default:
                    break;
                }
                break;
            
            default:
                mapTemp[x][y] = 'U';
                break;
            }
        } else 
        {
            switch (cells[i].cellType)
            {
            case Grassland_Cell:
                mapTemp[x][y] = '-';
                break;
            case Sea_Cell:
                mapTemp[x][y] = 'o';
                break;
            default:
                break;
            }
        }
    }
    for (int i = 0; i < MAX_Y; i++)
	{
		for (int j = 0; j < MAX_X; j++)
		{
			std::cout << mapTemp[j][i];
		}
		std::cout << std::endl;
	}
    std::cout << std::endl;
}
