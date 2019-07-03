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

void BuildingList::update() {


	if (isBuildTrue) {
		Building* castle1= new Castle(1);
		addBuilding(castle1);
		castle1->setx(x);
		castle1->sety(y);
	}
}

void BuildingList::render() {
	if (bl.empty() == false) {
		for (int i = 0; i < bl.size(); i++) {
			al_draw_bitmap(AssetLoader::manager->getImage("castle"), bl[i]->getx(), bl[i]->gety(), 0);
		}
	}
}