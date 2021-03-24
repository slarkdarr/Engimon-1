#ifndef BAG_H
#define BAG_H

#include "Species/Engimon.hpp"
#include "Inventory.hpp"

template<class T>
class Bag  
{	
	public:
		T** listItem;
		int neff;
		bool Add(T& other);
		void printAllInfo();
		Bag();
		~Bag();

};
#endif