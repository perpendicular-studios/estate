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



	
	void setBuild(bool b) { isBuildTrue = b; }
	void setx(int x_) { x = x_; }
	void sety(int y_) { y = y_; }
private:
	std::vector<Building*> bl; 
	bool isBuildTrue = false;
	int x, y;
};

#endif 