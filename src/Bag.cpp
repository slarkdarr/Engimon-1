#include "Bag.hpp"  


Bag::Bag()
{
	this->listEngimon = new Engimon*[MAX_CAPACITY];
    this->neff =0; 
}

bool Bag::Add(Engimon& other)
{
    if (neff <= MAX_CAPACITY)
    {
        this->listEngimon[neff] = &other;
        neff++;
        return true;
    }
    return false;
}

void Bag::printAllInfo()
{
    for (int i = 0; i < neff; i++)
    {
        std::cout << (i+1) << std::endl;
        this->listEngimon[i]->printInfo();
        std::cout << std::endl;
    }
    
}


	
Bag::~Bag()
{
	
}

