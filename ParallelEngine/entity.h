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

	bool contains(int x, int y) { return hitbox.contains(Vector2i(x, y)); }
	bool contains(Rectangle<int> other) { return hitbox.contains(other); }
	bool contains(Entity * other) { return hitbox.contains(other->hitbox); }
	bool intersects(Rectangle<int> other) { return hitbox.intersects(other); }
	bool intersects(Entity * entity) { return hitbox.intersects(entity->hitbox); }

	void setLeft(bool b) { left = b; }
	void setRight(bool b) { right = b; }
	void setUp(bool b) { up = b; }
	void setDown(bool b) { down = b; }

	virtual void render() = 0;
	virtual void update(ALLEGRO_KEYBOARD_STATE & ks) = 0;
protected:
	int x, y;
	int cwidth, cheight; // collision width and height (the hitbox dimensions)
	int width, height;
	int xtemp, ytemp; // storage for old position before collision
	int moveSpeed; // velocity
	int dx, dy;
	int topTile, bottomTile, leftTile, rightTile;
	bool topCollision, bottomCollision, leftCollision, rightCollision;
	bool checkTileMapCollision();
	Rectangle<int> hitbox;
	AnimationSet animationSet;
	TileMap * tm;
	int tileSize;
	bool left = false, right = false, up = false, down = false;
private:
	void calculateCollision(int x, int y);
};

#endif ENTITY_H