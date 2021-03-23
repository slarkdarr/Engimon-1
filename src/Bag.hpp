#ifndef BAG_H
#define BAG_H

#include "Species/Engimon.hpp"
#include "Inventory.hpp"


class Bag  
{	
	public:
		Engimon** listEngimon;
		int neff;
		bool Add(Engimon& other);
		void printAllInfo();
		Bag();
		~Bag();

};
#endif