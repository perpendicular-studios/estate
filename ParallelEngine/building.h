#ifndef BUILDING_H
#define BUILDING_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <string>
#include "animationset.h"
#include "tilemap.h"
#include "assetloader.h"
#include "resources.h"

class Building {	
public:
	Building(ALLEGRO_BITMAP* bitmap, int width, int height);

	int getx() const { return x; }
	int gety() const { return y; }
	void setx(int x_) {  x = x_; }
	void sety(int y_) { y = y_; }
	int getCol() const { return col; }
	int getRow() const { return row; }
	void setCol(int col_) { col = col_; }
	void setRow(int row_) { row = row_; }
	int getColWidth() const { return colWidth; }
	int getRowHeight() const { return rowHeight; }


	void draw(ALLEGRO_BITMAP* bitmap, float x, float y);
	void draw_interface(ALLEGRO_BITMAP* bitmap, float x, float y);
	virtual ALLEGRO_BITMAP* getBaseImg() { return bitmap; }
	
	int getWidth() { return width; }
	int getHeight() { return height; }
	int getID() { return id; }
	void setID(int id_) { id = id_; }

	int getHp() const { return hp; }
	int loseHp(int dmg) { hp -= dmg; }
	bool isStanding() { return hp > 0; }

	int getStoneCost() const { return stone; }
	int getWoodCost() const { return wood; }
	int getFoodCost() const { return food; }
	int getGoldCost() const { return gold; }

	bool requiresItems() const { return misc.empty(); }
	std::vector<std::pair<const Resource*, int>> getRequiredItems() const { return misc; }

protected:
	int x = 0, y = 0;
	int col = 0, row = 0;
	int colWidth = 0, rowHeight = 0;
	int width, height;
	std::shared_ptr<TileMap> tm;
	int id;
	int stone, wood, food, gold;
	std::vector<std::pair<const Resource*, int>> misc; // other required misc items, and quantity of that misc item
	int hp;
	int lvl;
	ALLEGRO_BITMAP* bitmap;

};

#endif