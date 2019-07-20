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

void BuildingList::checkPlacingBounds(Building* b) {
	b->setCol(col);
	b->setRow(row);
	if (b->getRow() - b->getRowHeight() < 0 || b->getCol() - b->getColWidth() < 0) {
		isOccupied = true;
		std::cout << "Cannot place in this location \n";
		isPlacingTrue = false;
	}
	else {
		for (int row_ = b->getRow(); row_ >= b->getRow() - b->getRowHeight(); row_--) {
			for (int col_ = b->getCol(); col_ >= b->getCol() - b->getColWidth(); col_--) {
				if (tm->checkOccupied(row_, col_)) {
					isOccupied = true;
					std::cout << "Cannot place in this location \n";
					isPlacingTrue = false;
					isOccupied = true;
					row_ = col_ = 0;
				}
			}
		}
	}
}

void BuildingList::update(Building* b, std::string buildingType) {
	if (isBuildTrue) { 
		if (isPlacingTrue) {
			checkPlacingBounds(b);
			if (isOccupied == false) {
				if (buildingType == "Castle") { b = new Castle(bl.size()); }
				else if (buildingType == "Towncenter") { b = new Towncenter(bl.size()); }
				addBuilding(b);
				b->setx(x);
				b->sety(y);
				b->setCol(col);
				b->setRow(row);
				std::cout << b->getRow() << "," << b->getCol() << "\n";
				std::cout << b->getRow() - b->getRowHeight() << "," << b->getCol() - b->getColWidth() << "\n";
				for (int row_ = b->getRow(); row_ >= b->getRow() - b->getRowHeight(); row_--) {
					for (int col_ = b->getCol(); col_ >= b->getCol() - b->getColWidth(); col_--) {
						tm->setOccupied(row_, col_);
						std::cout << "Occupied Tile: " << row_ << "," << col_ << "\n";
					}
				}
				isPlacingTrue = false;
			}
			isOccupied = false;
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

void BuildingList::placingBuilding(std::string buildingType, float x, float y) {
	ALLEGRO_BITMAP* bitmap = AssetLoader::manager->getImage("castle");						// set default value in case of error
	if (buildingType == "Castle") { bitmap = AssetLoader::manager->getImage("castle"); }
	else if (buildingType == "Towncenter") { bitmap = AssetLoader::manager->getImage("towncenter"); }
	al_draw_bitmap(bitmap, x, y, 0);
}