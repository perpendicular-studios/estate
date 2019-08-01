#ifndef INVENTORY_H
#define INVENTORY_H
#include "resources.h"
#include <map>
#include <vector>

class Inventory {
public:
	Inventory(int f, int g, int w, int s) : food(f), gold(g), wood(w), stone(s) {}
	void addGeneralResource(const GeneralResource* res);
	void addMiscResource(const MiscResource* res, int quantity);
	void removeGeneralResource(ResourceType res, int quantity);
	void removeMiscResource(const MiscResource * res, int quantity);

	int getFood() const { return food; }
	int getGold() const { return gold; }
	int getWood() const { return wood; }
	int getStone() const { return stone; }

	bool hasItems() { return inventory.empty(); }
	bool hasItem(std::string key) { return !(inventory[key].empty()); } //if not empty, inventory has item

	std::vector<std::vector<const MiscResource*>> getMiscResources();

private:
	std::map<std::string, std::vector<const MiscResource*>> inventory;
	int food;
	int gold;
	int wood;
	int stone;
};


#endif