#ifndef ENTITY_H
#define ENTITY_H
#include "tilemap.h"
#include "resources.h"
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <string>
#include "var.h"
class Entity {
public:
	Entity(TileMap* tm_, int tileCost_, int food, int gold, int stone, int wood, ALLEGRO_BITMAP * img_, int x, int y);
	~Entity();

	virtual Entity* clone() const = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	virtual void drawEntityWindow() = 0;
	void drawEntityWindowBackground();
	void drawEntityHP();

	float getx() const { return x; }
	float gety() const { return y; }

	bool setPosition(int x_, int y_);
	Vector2f findNearestUnoccupiedPos(int x_, int y_);

	int getTileType() {
		return tm->getType(getrow(), getcol());
	}

	int getTileID() {
		return tm->getTile(getrow(), getcol());
	}

	void renderRadius();
	void moveTo(int x, int y);

	void setcol(float col_) { col = col_; }
	void setrow(float row_) { row = row_; }

	float getcol() const { 
		return row;
	}

	float getrow() const {
		return col;
	}

//	Vector2f getTileCenter();

	int getFoodCost() const { return food; }
	int getGoldCost() const { return gold; }
	int getStoneCost() const { return stone; }
	int getWoodCost() const { return wood; }
	int getTileCost() const { return tileCost; }
	std::string getEntityTypeString() const { return entityTypeString; }

	std::vector<Resource*> getRequiredItems() { return requiredItems; }

	ALLEGRO_BITMAP* getImage() { return img; }

	bool operator==(Entity* rhs);
protected:
	TileMap* tm;	
	float x, y;
	int row, col;
	int xdest, ydest;
	int tileCost; // amount of tiles that unit can move per turn
	int food, gold, stone, wood;
	int currHp, hp;
	std::string entityTypeString;
	std::vector<Resource*> requiredItems;
	ALLEGRO_BITMAP* img;
	ALLEGRO_FONT* basic_font20 = al_load_font("basicfont.ttf", 20, 0);
	ALLEGRO_FONT* basic_font15 = al_load_font("basicfont.ttf", 15, 0);
};

#endif