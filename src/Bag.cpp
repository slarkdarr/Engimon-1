#include "Bag.hpp"  

template <class T>
Bag<T>::Bag()
{
	this->listItem = new T*[MAX_CAPACITY];
    this->neff =0; 
}
template <class T>
bool Bag<T>::Add(T& other)
{
    if (neff <= MAX_CAPACITY)
    {
        this->listItem[neff] = &other;
        neff++;
        return true;
    }
    return false;
}
template <class T>
void Bag<T>::printAllInfo()
{
    for (int i = 0; i < neff; i++)
    {
        std::cout << (i+1) << std::endl;
        this->listItem[i]->printInfo();
        std::cout << std::endl;
    }
    
}

template <class T>
Bag<T>::~Bag()
{
	
}

template class Bag<Skill>;
template class Bag<Engimon>;
