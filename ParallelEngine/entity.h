#ifndef ENTITY_H
#define ENTITY_H
#include "tilemap.h"
class Entity {
public:
	Entity(TileMap* tm_);
	~Entity();
	
	virtual void update() = 0;
	virtual void render() = 0;

	int getx() { return x; }
	int gety() { return y; }

	int getTileType() {
		return tm->getType(getrow(), getcol());
	}

	int getTileID() {
		return tm->getTile(getrow(), getcol());
	}
private:
	TileMap* tm;
	int x, y;

	int getcol() { return tm->screenToIso(x, y).x; }
	int getrow() { return tm->screenToIso(x, y).y; }
};

#endif