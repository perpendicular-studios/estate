#ifndef BUILDING_H
#define BUILDING_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "animationset.h"
#include "tilemap.h"

class Building {	
public:
	Building(std::shared_ptr<TileMap> tm);

	int getx() const { return x; }
	int gety() const { return y; }

	void draw(ALLEGRO_BITMAP* bitmap, float x, float y);
	void draw_interface(ALLEGRO_BITMAP* bitmap, float x, float y);

	virtual void render() = 0;
	virtual void update() = 0;
	
	int getID() { return id; }
	void setID(int id_) { id = id_; }

	int getHp() const { return hp; }
	int loseHp(int dmg) { hp -= dmg; }
	bool isStanding() { return hp > 0; }
protected:
	int x = 0, y = 0;
	int width = 0, height = 0;
	std::shared_ptr<TileMap> tm;
	int id;
	int stone, metal, wood, food, gold;
	int hp;
	int lvl;

};

#endif