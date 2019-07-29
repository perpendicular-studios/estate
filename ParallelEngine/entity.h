#ifndef ENTITY_H
#define ENTITY_H
#include "tilemap.h"
#include "resources.h"
class Entity {
public:
	Entity(TileMap* tm_, int tileCost_, int food, int gold, int stone, int wood, ALLEGRO_BITMAP * img_, int x, int y);
	~Entity();

	virtual Entity* clone() const = 0;
	virtual void update() = 0;
	virtual void render() = 0;

	int getx() const { return x; }
	int gety() const { return y; }

	void setPosition(int x_, int y_);

	int getTileType() {
		return tm->getType(getrow(), getcol());
	}

	int getTileID() {
		return tm->getTile(getrow(), getcol());
	}

	void renderRadius();
	void moveTo(int x, int y);

	int getcol() const { return tm->screenToIso(x, y).x; }
	int getrow() const { return tm->screenToIso(x, y).y; }

	int getFoodCost() const { return food; }
	int getGoldCost() const { return gold; }
	int getStoneCost() const { return stone; }
	int getWoodCost() const { return wood; }
	int getTileCost() const { return tileCost; }
	// TODO: might need some refactoring
	TileMap* getTileMap() const { return tm; }
	std::vector<Resource*> getRequiredItems() { return requiredItems; }

	ALLEGRO_BITMAP* getImage() { return img; }

	bool operator==(Entity* rhs) { return (this->getrow() == rhs->getrow() && this->getcol() == rhs->getcol()); }
protected:
	TileMap* tm;
	int x, y;
	int xdest, ydest;
	int tileCost; // amount of tiles that unit can move per turn
	int food, gold, stone, wood;
	std::vector<Resource*> requiredItems;
	ALLEGRO_BITMAP* img;
};

#endif