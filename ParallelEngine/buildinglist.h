#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"
#include "castle.h"
#include "towncenter.h"
//#include "tilemap.h"

class BuildingList {
public:

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
	// place building
	void placingBuilding(std::string buildingType, float x, float y); // buildingImg will select from a switch to get correct building img
	
	void setBuild(bool b) { isBuildTrue = b; }
	void setPlacing(bool p) { isPlacingTrue = p; }

	bool getPlacing() { return isPlacingTrue; }

	void setx(int x_) { x = x_; }
	void sety(int y_) { y = y_; }
	void setCol(int col_) { col = col_; }
	void setRow(int row_) { row = row_; }
private:
	std::vector<Building*> bl; 
	bool isBuildTrue = false, isPlacingTrue = false;
	int x, y;
	int col, row;
};

#endif 