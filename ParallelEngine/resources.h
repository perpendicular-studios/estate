#ifndef RESOURCES_H
#define RESOURCES_H
#include <string>
#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include "assetloader.h"
enum ResourceType { FOOD, WOOD, STONE, GOLD };

class Resource {
public:
	static const int GENERAL = 0;
	static const int MISC = 1;

	ALLEGRO_BITMAP* getTileImage() const { return AssetLoader::manager->getImage("tile_" + name); }
	std::string getName() const { return name; }
	virtual int getType() const = 0;
protected:
	Resource(std::string name_) : name(name_) {}
	std::string name;
};

class MiscResource : public Resource { 
public:
	MiscResource(std::string name, std::string desc_) : Resource(name), desc(desc_) {}
	void render(int x, int y) const { al_draw_bitmap(AssetLoader::manager->getImage(name), x, y, 0); }
	int getType() const { return MISC; }
	std::string getDescription() const { return desc; }
private:
	std::string desc;
};

class GeneralResource : public Resource {
public:
	GeneralResource(std::string name, ResourceType type_, int yield_) : Resource(name), type(type_), yield(yield_) {}
	ResourceType getResourceType() const { return type; }
	int getYield() const { return yield; }
	int getType() const { return GENERAL; }
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

static const MiscResource* CLOTH = new MiscResource("cloth", "Place loom adjacent to harvest");
static const MiscResource* IRON_ORE = new MiscResource("iron", "Place furnace adjacent to harvest");

// The id that each resource is referred to is the index in this list + the number of other map tiles. E.x. if there are 5 tiles in the map, wheat is 5, rice is 6, etc...
static const Resource* allResource[3] = { WHEAT, RICE, IRON_ORE };

#endif