#ifndef MAP_H
#define MAP_H

#include "Cell.hpp"
#include <iostream>
#include <fstream>
class Cell;

class Map  
{

	public:
		int MAX_X, MAX_Y;

		Cell* cells;

		Map(int x, int y);
		Map(const char* namafile);
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