#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"
#include "castle.h"
//#include "tilemap.h"

class BuildingList {
public:
	BuildingList() {}
	~BuildingList();

	// initialize new building, adds to list.
	void addBuilding(Building *buildingObject);
	// delete building with buildingID
	void popBuilding(int buildingID);
	// clear all buildings
	void clearList();
	// update buildlist objects
	void update();
	// render buildlist objects
	void render();
	// place building
	void placingBuilding(int buildingImg, float x, float y); // buildingImg will select from a switch to get correct building img
	
	void setBuild(bool b) { isBuildTrue = b; }
	void setPlacing(bool p) { isPlacingTrue = p; }
	bool getPlacing() { return isPlacingTrue; }
	void setx(int x_) { x = x_; }
	void sety(int y_) { y = y_; }
private:
	std::vector<Building*> bl; 
	bool isBuildTrue = false, isPlacingTrue = false;
	int x, y;
};

#endif 