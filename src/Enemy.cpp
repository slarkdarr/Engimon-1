#include "Enemy.hpp"  
	
Enemy::Enemy(Map& m, ElementType elemen, int x, int y) : Occupier(m, x, y, Enemy_Type)
{
	this->engimon = new Dragon();
    this->map = &m;
}
	
Enemy::~Enemy()
{
	delete engimon;
}