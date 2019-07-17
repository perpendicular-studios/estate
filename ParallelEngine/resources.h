#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "assetloader.h"
enum ResourceType { FOOD, WOOD, STONE, GOLD, MISC };

class Resource {
public:
	Resource(std::string name_, ResourceType type_, int yield_) : name(name_), type(type_), yield(yield_) { }
	std::string getName() const { return name; }
	ResourceType getResourceType() const { return type; }
	int getYield() const { return yield; }
	void drawImage(std::string key, int x, int y) const { al_draw_bitmap(AssetLoader::manager->getImage(key), x, y, 0); }
private:
	std::string name;
	ResourceType type;
	int yield;
};

// yield is in number of resource per turn, when a peasant is present to harvest the tile.
static const Resource* WHEAT = new Resource("Wheat", FOOD, 10);
static const Resource* RICE = new Resource("Rice", FOOD, 15);
static const Resource* CHICKEN = new Resource("Chicken", FOOD, 10);
static const Resource* MUTTON = new Resource("Mutton", FOOD, 20);

static const Resource* LIGHT_WOOD = new Resource("l_wood", WOOD, 10);
static const Resource* HEAVY_WOOD = new Resource("h_wood", WOOD, 50);
static const Resource* LIGHT_GOLD_ORE = new Resource("l_gold", GOLD, 10);
static const Resource* HEAVY_GOLD_ORE = new Resource("h_gold", GOLD, 50);
static const Resource* LIGHT_STONE_ORE = new Resource("l_stone", STONE, 10);
static const Resource* HEAVY_STONE_ORE = new Resource("h_stone", STONE, 10);

static const Resource* WOOL = new Resource("Cloth", MISC, 1);
static const Resource* IRON_ORE = new Resource("Iron", MISC, 1);

#endif