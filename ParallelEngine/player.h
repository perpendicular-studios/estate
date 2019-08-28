#ifndef PLAYER_H
#define PLAYER_H
#include "inventory.h"
#include "entity.h"
#include "resources.h"
#include "building.h"
#include "tilemap.h"
#include "buildinglist.h"
#include <string>
#include <vector>
#include <unordered_map>
class Player {
public:
	Player() { inventory = new Inventory(0,0,0,0); }

	void updateInventory(); //turn by turn update
	bool buyBuilding(Building* building);
	bool buyEntity(Entity* entity);

	int getGold() { return inventory->getGold(); }
	int getStone() { return inventory->getStone(); }
	int getWood() { return inventory->getWood(); }
	int getFood() { return inventory->getFood(); }

	Inventory* getInventory() { return inventory; }
	void addTileToInventory(int tileID);

	Entity* entityInTile(int row, int col);
	void renderEntities();
	void addEntity(Entity* e);
	void updateEntityPosition(Entity* e, int row, int col);
private:
	std::map<std::pair<int, int>, Entity*> entities;
	Inventory * inventory;
};


#endif