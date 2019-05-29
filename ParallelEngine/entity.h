#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "animationset.h"
#include "tilemap.h"

class Entity {
public:
	Entity(TileMap * tm, std::string key);

	int getx() const { return x; }
	int gety() const { return y; }
	Vector2i getPosition() { return Vector2i(x, y); }

	int getid() { return id; }

	void setx(int x) { this->x = x; }
	void sety(int y) { this->y = y; }
	void setTargetLocation(int x, int y) {
		xdest = x;
		ydest = y;
	}

	Vector2i getTargetLocation() { return Vector2i(xdest, ydest); }
	std::string getKey() { return key; }

	virtual void render() = 0;
	virtual void update() = 0;
protected:
	int x, y;
	int width, height;
	int moveSpeed; // velocity
	int dx, dy;
	TileMap * tm;
	bool left = false, right = false, up = false, down = false;
	int xdest, ydest;
	int tilesCanMove;
	int id;
	std::string key;

	void updateLocation();
};

#endif ENTITY_H