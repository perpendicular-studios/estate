#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "animationset.h"
#include "tilemap.h"

class Entity {
public:
	Entity(std::shared_ptr<TileMap> tm, int id);

	int getx() const { return x; }
	int gety() const { return y; }


	virtual void render() = 0;
	virtual void update() = 0;
protected:
	int x = 0, y = 0;
	int width = 0, height = 0;
	int moveSpeed; 
	int dx = 0, dy = 0;
	std::shared_ptr<TileMap> tm;
	bool left = false, right = false, up = false, down = false;
	int id;

	void move(int xdest, int ydest);
};

#endif ENTITY_H