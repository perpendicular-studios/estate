#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"
#include "castle.h"
#include "towncenter.h"
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
	void update(Building* b, std::string buildingType);
	// render buildlist objects
	void render();
	//check placing bounds
	bool checkPlacingBounds(Building* b);
	// place building
	void placingBuilding(Building* b, float x, float y); // buildingImg will select from a switch to get correct building img
	
	void setPlacing(bool p) { isPlacingTrue = p; }
	void setCurrBuilding(Building* b) { currBuilding = b; }

	bool getPlacing() { return isPlacingTrue; }

	void setx(int x_) { x = x_; }
	void sety(int y_) { y = y_; }
	void setCol(int col_) { col = col_; }
	void setRow(int row_) { row = row_; }
private:
	std::shared_ptr<TileMap> tm;
	std::vector<Building*> bl; 
	bool isPlacingTrue = false;
	int x, y;
	int col, row;
	int numID = 0;
	Building* currBuilding;
};

#endif 