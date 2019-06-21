#ifndef BUILDINGLIST_H
#define BUILDINGLIST_H

#include <vector>
#include "building.h"

class BuildingList {
public:
	// initialize new building, adds to list.
	void addBuilding();

private:
	std::vector<Building> buildingList;
};

#endif 