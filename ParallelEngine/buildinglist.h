#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"
#include "castle.h"
#include "towncenter.h"
#include "market.h"
#include "tilemap.h"

class BuildingList {
public:
	BuildingList(std::shared_ptr<TileMap> tm_) : tm(tm_) {}

	// initialize new building, adds to list.
	void addBuilding(Building *buildingObject);
	// delete building with buildingID
	void popBuilding(int buildingID);
	// clear all buildings
	void clearList();
	// update buildlist objects
	void update(Building* b, Player* p);
	// render buildlist objects
	void render();
	//check placing bounds
	bool checkPlacingBounds(Building* b);
	// place building
	void placingBuilding(Building* b, float x, float y); // buildingImg will select from a switch to get correct building img
	//check which building is in front
	bool isBuilding1InFront(Building* b1, Building* b2);
	//loop through to see if click is on a building tile
	Building* isTileInBounds(int currCol, int currRow);
	//produce units
	void produceUnits();

	
	void setPlacing(bool p) { isPlacingTrue = p; }
	bool getPlacing() { return isPlacingTrue; }
	void setCurrBuilding(Building* b) { currBuilding = b; }
	int getSize() { return bl.size(); }

	void setx(float x_) { x = x_; }
	float getx() { return x; }
	void sety(float y_) { y = y_; }
	float gety() { return y; }
	void setCol(float col_) { col = col_; }
	float getCol() { return col; }
	void setRow(float row_) { row = row_; }
	float getRow() { return row; }
	Building* getCurrBuilding() { return currBuilding; }

private:
	std::shared_ptr<TileMap> tm;
	std::vector<Building*> bl; 
	bool isPlacingTrue = false;
	float x, y;
	float col, row;
	int numID = 0;
	Building* currBuilding;
};

#endif 