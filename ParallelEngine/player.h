#ifndef PLAYER_H
#define PLAYER_H
#include "inventory.h"
#include "entity.h"
#include <vector>
class Player {
public:
	void updateInventory();
private:
	std::vector<Entity*> entities;
	Inventory * inventory;
};


#endif