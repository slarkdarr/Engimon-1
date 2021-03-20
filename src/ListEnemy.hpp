#ifndef LISTENEMY_H
#define LISTENEMY_H
#include "Enemy.hpp"
#include "Player.hpp"
class ListEnemy  
{
	public:
		Enemy** listEnemy;
		Player* currentplayer;
		Map* map;
		ListEnemy(Map& map, Player& player);
		ListEnemy(Map& map, Player& player, int size);
		~ListEnemy();

};
#endif