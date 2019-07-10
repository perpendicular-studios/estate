#ifndef INVENTORY_H
#define INVENTORY_H
#include "resources.h"
#include <map>

class Inventory {
public:
	Inventory(int f, int g, int w, int s) : food(f), gold(g), wood(w), stone(s) {}
	void addResource(Resource * res);
	void removeResource(Resource * res, int quantity);

private:
	std::map<std::string, Resource*> inventory;
	int food;
	int gold;
	int wood;
	int stone;
};


#endif