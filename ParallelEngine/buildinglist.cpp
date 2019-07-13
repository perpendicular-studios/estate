#include "buildinglist.h"
#include <vector>

void BuildingList::addBuilding(Building* buildingObject) {
	bl.push_back(buildingObject);
	buildingObject->setID(bl.size() - 1);
 }

void BuildingList::popBuilding(int buildingID) {
	bl.erase(bl.begin() + buildingID);
	
	for (int i = buildingID; i < bl.size(); i++) {
		bl[i]->setID(i);
	}
}

void BuildingList::clearList() {
	bl.clear();
}

void BuildingList::update(Building* b, std::string buildingType) {
	if (isBuildTrue) { 
		if (isPlacingTrue) {
			if (buildingType == "Castle") { b = new Castle(bl.size()); }
			addBuilding(b);
			b->setx(x);
			b->sety(y);
			
			isPlacingTrue = false;
		}
		else if (isPlacingTrue == false) { isPlacingTrue = true;}
		isBuildTrue = false;
	}
}

void BuildingList::render() {

	if (bl.empty() == false) {
		for (int i = 0; i < bl.size(); i++) {
			al_draw_bitmap(bl[i]->getBaseImg() , bl[i]->getx(), bl[i]->gety(), 0);
		}
	}
}

void BuildingList::placingBuilding(int buildingImg, float x, float y) {
	al_draw_bitmap(AssetLoader::manager->getImage("castle"), x, y, 0);
}