#ifndef INVENTORY_H
#define INVENTORY_H
#include "resources.h"
#include <map>
#include <vector>

class Inventory {
public:
	Inventory(int f, int g, int w, int s) : food(f), gold(g), wood(w), stone(s) {}
	void addResource(const Resource * res);
	void removeResource(ResourceType res, int quantity);
	void removeResource(const Resource * res, int quantity);
private:
	std::map<std::string, std::vector<const Resource*>> inventory;
	int food;
	int gold;
	int wood;
	int stone;
};


#endif