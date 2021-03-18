#ifndef MAP_H
#define MAP_H

#include "Cell.hpp"

#define MAX_X 30
#define MAX_Y 20

class Map  
{
	private:
		Cell* cells;
	public:
		Map();
		~Map();
		// Membuat Grassland sesuai luas MAX_Y * MAX_X
		void createGrassland();

		// Membuat Sea sesuai luas MAX_Y * MAX_X
		void createSea();

		// Membuat Grassland sesuai area
		void setGrassland(int x_kiri, int x_kanan, int y_kiri, int y_kanan);

		// Membuat Grassland sesuai area
		void setSea(int x_kiri, int x_kanan, int y_kiri, int y_kanan);

		void printMap(int currentlevel);
};
#endif