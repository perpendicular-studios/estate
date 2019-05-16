#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "animationset.h"
#include "rectangle.h"
#include "tilemap.h"
#include "vec2.h"

class Entity {
public:
	Entity(TileMap * tm);

	int getx() const;
	int gety() const;
	void setx(int x);
	void sety(int y);

	void setLeft(bool b) { left = b; }
	void setRight(bool b) { right = b; }
	void setUp(bool b) { up = b; }
	void setDown(bool b) { down = b; }

	virtual void render() = 0;
	virtual void update() = 0;
protected:
	int x, y;
	int width, height;
	int xtemp, ytemp; // storage for old position before collision
	int moveSpeed; // velocity
	int dx, dy;
	AnimationSet animationSet;
	TileMap * tm;
	int tileSize;
	bool left = false, right = false, up = false, down = false;
};

#endif ENTITY_H