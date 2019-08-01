#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "assetloader.h"
enum ResourceType { FOOD, WOOD, STONE, GOLD };

class Resource {
public:
	ALLEGRO_BITMAP* getTileImage() const { return AssetLoader::manager->getImage("tile_" + name); }
	std::string getName() const { return name; }
protected:
	Resource(std::string name_) : name(name_) {}
	std::string name;
};

class MiscResource : public Resource { 
public:
	MiscResource(std::string name, std::string img_key_) : Resource(name), img_key(img_key_) {}
	void render(int x, int y) const { al_draw_bitmap(AssetLoader::manager->getImage(img_key), x, y, 0); }
private:
	std::string img_key;
};

class GeneralResource : public Resource {
public:
	GeneralResource(std::string name, ResourceType type_, int yield_) : Resource(name), type(type_), yield(yield_) {}
	ResourceType getResourceType() const { return type; }
	int getYield() const { return yield; }
private:
	ResourceType type;
	int yield;
};

// yield is in number of resource per turn, when a peasant is present to harvest the tile.
static const GeneralResource* WHEAT = new GeneralResource("wheat", FOOD, 10);
static const GeneralResource* RICE = new GeneralResource("rice", FOOD, 15);
static const GeneralResource* CHICKEN = new GeneralResource("chicken", FOOD, 10);
static const GeneralResource* MUTTON = new GeneralResource("mutton", FOOD, 20);

static const GeneralResource* TREE = new GeneralResource("tree", WOOD, 10);
static const GeneralResource* LIGHT_GOLD_ORE = new GeneralResource("light_gold", GOLD, 10);
static const GeneralResource* HEAVY_GOLD_ORE = new GeneralResource("heavy_gold", GOLD, 50);
static const GeneralResource* LIGHT_STONE_ORE = new GeneralResource("light_stone", STONE, 10);
static const GeneralResource* HEAVY_STONE_ORE = new GeneralResource("heavy_stone", STONE, 10);

static const MiscResource* CLOTH = new MiscResource("Cloth", "cloth");
static const MiscResource* IRON_ORE = new MiscResource("Iron", "iron");

#endif