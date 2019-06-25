#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"

class BuildingList {
public:
	BuildingList() {}
	~BuildingList();

	// initialize new building, adds to list.
	void addBuilding(Building *buildingObject);

	void popBuilding(int buildingID);

	void clearList();
private:
	std::vector<Building*> bl; 
};

#endif 