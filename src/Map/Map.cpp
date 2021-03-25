#include "Map.hpp"  
#include "Cell.hpp"
#include <iostream>
#include <windows.h>

Map::Map(int x, int y)
{
    Map::MAX_X = x;
    Map::MAX_Y = y;
    Position::MAX_X = x;
    Position::MAX_Y = y;
	this->cells = new Cell[Map::MAX_X * Map::MAX_Y];
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        this->cells[i].setPosition(i % Map::MAX_X, i / Map::MAX_X);
    }
}
	
Map::~Map()
{
	delete[] cells;
}

Map::Map(const char* namafile)
{
    std::string line;
    std::ifstream myfile (namafile);
    int maks_x = 0;
    int maks_y = 0;
    if (myfile.is_open())
    {
        std::getline (myfile,line);
        ++maks_y;
        maks_x = line.length();
        while ( std::getline (myfile,line) )
        {
            if (line != "") ++maks_y;
        }
        myfile.close();
    }
    else {
        std::cout << "file tidak di temukan" << std::endl;
    }
    Map::MAX_X = maks_x;
    Map::MAX_Y = maks_y;
    Position::MAX_X = maks_x;
    Position::MAX_Y = maks_y;

    this->cells = new Cell[Map::MAX_X * Map::MAX_Y];
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        this->cells[i].setPosition(i % Map::MAX_X, i / Map::MAX_X);
    }
    std::ifstream myfile2 (namafile);
    std::string line2;
    if (myfile2.is_open())
    {
        int counter = 0;
        while ( std::getline (myfile2,line2) )
        {
            for (int i = 0; i < line2.length(); i++)
            {
                if (line2[i] == 'o') this->cells[counter].setCellType(Sea_Cell);
                ++counter;
            }
        }
        myfile2.close();
    }
}


void Map::createGrassland()
{
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        this->cells[i].setCellType(Grassland_Cell);
    }
}

// Membuat Sea sesuai luas Map::MAX_Y * Map::MAX_X
void Map::createSea()
{
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        this->cells[i].setCellType(Sea_Cell);
    }
}

// Membuat Grassland sesuai area, mereturn true jika berhasil
void Map::setGrassland(int x_kiri, int x_kanan, int y_kiri, int y_kanan)
{
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        int x = i % Map::MAX_X;
        int y = i / Map::MAX_X;
        if (x >= x_kiri && x <= x_kanan && y >= y_kiri && y <= y_kanan) 
        {
            this->cells[i].setCellType(Grassland_Cell);
        } 
    }
}

// Membuat Grassland sesuai area, mereturn true jika gagal
void Map::setSea(int x_kiri, int x_kanan, int y_kiri, int y_kanan)
{
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        int x = i % Map::MAX_X;
        int y = i / Map::MAX_X;
        if (x >= x_kiri && x <= x_kanan && y >= y_kiri && y <= y_kanan) 
        {
            this->cells[i].setCellType(Sea_Cell);
        } 
    }
}

void Map::printMap(int currentlevel)
{

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int i = 0; i < Map::MAX_X * Map::MAX_Y; i++)
    {
        int x = i % Map::MAX_X;
        if (x == 0) std::cout << std::endl;
        // Jika ada Occupierz
        char c;
        int colorMultiplier = 0;
        int hashCellChar = 0;
        bool condition = false;

        if (this->cells[i].occupier)
        {
            condition = (cells[i].occupier->getLevel() >= currentlevel);
            switch (this->cells[i].occupier->ocpType)
            {
            case Player_Type:
                c = 'P';
                colorMultiplier = 15;
                break;
            case Pet_Type:
                // Jika engimon == nullptr, tidak passtrough ke enemy
                if (!this->cells[i].occupier->getEngimon()) break;
            case Enemy_Type:
                switch (cells[i].occupier->getElement1())
                {
                case Fire:
                    c = (condition) ? 'F' : 'f';
                    hashCellChar = 1;
                    colorMultiplier = 12;
                    break;
                case Water:
                    c = (condition) ? 'W' : 'w';
                    hashCellChar = 10;
                    colorMultiplier = 1;

                    break;
                case Electric:
                    c = (condition) ? 'E' : 'e';
                    hashCellChar = 100;
                    colorMultiplier = 6;

                    break;
                case Ground:
                    c = (condition) ? 'G' : 'g';
                    hashCellChar = 1000;
                    colorMultiplier = 8;

                    break;
                case Ice:
                    c = (condition) ? 'I' : 'i';
                    hashCellChar = 10000;
                    colorMultiplier = 7;
                    break;

                default:
                    break;
                }
                switch (cells[i].occupier->getElement2())
                {
                case None:
                    break;
                case Fire:
                    hashCellChar += 1;
                    break;
                case Water:
                    hashCellChar += 10;
                    break;
                case Electric:
                    hashCellChar += 100;
                    break;
                case Ground:
                    hashCellChar += 1000;
                    break;
                case Ice:
                    hashCellChar += 10000;
                    break;
                
                default:
                    break;
                }
                if (hashCellChar == 101 ){
                    c = (condition) ? 'L' : 'l';
                    colorMultiplier = 13;
                }
                if (hashCellChar == 1010 ){
                    c = (condition) ? 'N' : 'n';
                    colorMultiplier = 8;
                }
                if (hashCellChar == 10010 ){
                    c = (condition) ? 'S' : 's';
                    colorMultiplier = 11;
                }
                break;
            
            default:
                c = 'U';
                break;
            }
        } else 
        {
            switch (cells[i].cellType)
            {
            case Grassland_Cell:
                c = '-';
                colorMultiplier = 10;
                break;
            case Sea_Cell:
                c = 'o';
                colorMultiplier = 3;
                break;
            default:
                break;
            }
        }
        switch (cells[i].cellType)
        {
        case Grassland_Cell:
            colorMultiplier += 160;
            break;
        case Sea_Cell:
            colorMultiplier += 48;
            break;
        default:
            break;
        }
        SetConsoleTextAttribute(hConsole, colorMultiplier);
        std::cout << c;
    }
    SetConsoleTextAttribute(hConsole, 15);
    std::cout << std::endl;
}
