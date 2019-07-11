#ifndef PLAYER_H
#define PLAYER_H
#include "inventory.h"
#include "entity.h"
#include "building.h"
#include <string>
#include <vector>
class Player {
public:
	void updateInventory(); //turn by turn update
	bool buyBuilding(Building* building);
private:
	std::vector<Entity*> entities;
	Inventory * inventory;
};


#endif