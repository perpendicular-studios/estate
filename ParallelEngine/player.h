#ifndef PLAYER_H
#define PLAYER_H
#include "inventory.h"
#include "entity.h"
#include "building.h"
#include "buildinglist.h"
#include <string>
#include <vector>
class Player {
public:
	Player() { inventory = new Inventory(0,0,0,0); }

	void updateInventory(); //turn by turn update
	bool buyBuilding(Building* building);

	int getGold() { return inventory->getGold(); }
	int getStone() { return inventory->getStone(); }
	int getWood() { return inventory->getWood(); }
	int getFood() { return inventory->getFood(); }

	Inventory* getInventory() { return inventory; }
	void addTileToInventory(int tileID);

	Entity* entityInTile(Vector2i clickCoord);
	void addEntity(Entity* e);
private:
	std::vector<Entity*> entities;
	Inventory * inventory;
};


#endif