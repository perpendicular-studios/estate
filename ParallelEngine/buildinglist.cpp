#include "buildinglist.h"
#include <vector>

void BuildingList::addBuilding(Building* buildingObject) {
	if (bl.empty()) { bl.push_back(buildingObject); }
	else {
		int i = 0;
		bool reachEnd = false;
		while ((bl[i]->getCol() - bl[i]->getColWidth() > buildingObject->getCol() || bl[i]->getRow() - bl[i]->getRowHeight() > buildingObject->getRow()) && reachEnd == false) {
			std::cout << "traversing \n";
			i++;
			if (i == bl.size()) { 
				reachEnd = true;
				i--;
			}
		}
		if (reachEnd == true) {
			std::cout << "Insert at front\n";
			bl.insert(bl.begin(), buildingObject);
		}
		else {
			while ((bl[i]->getCol() - bl[i]->getColWidth() <= buildingObject->getCol() && bl[i]->getRow() - bl[i]->getRowHeight() <= buildingObject->getRow()) && reachEnd == false) {
				std::cout << "traversing \n";
				i++;
				if (i == bl.size()) {
					reachEnd = true;
					i--;
				}
			}
			if (reachEnd == true) {
				std::cout << "Insert at end \n";
				bl.insert(bl.end(), buildingObject);
			}
			else {
				std::cout << "Inserting at " << i  << "\n";
				bl.insert(bl.begin() + i , buildingObject);
			}
			
		} 
	} 

	buildingObject->setID(numID);
	numID++;
 }

void BuildingList::popBuilding(int buildingID) {
	bl.erase(bl.begin() + buildingID);
}

void BuildingList::clearList() {
	bl.clear();
}

bool BuildingList::checkPlacingBounds(Building* b) {
	b->setCol(col);
	b->setRow(row);
	if (b->getRow() - b->getRowHeight() < 0 || b->getCol() - b->getColWidth() < 0) {
		return true;
	}
	else {
		for (int row_ = b->getRow(); row_ >= b->getRow() - b->getRowHeight(); row_--) {
			for (int col_ = b->getCol(); col_ >= b->getCol() - b->getColWidth(); col_--) {
				if (tm->checkOccupied(row_, col_)) {
					return true;
				}
			}
		}
	}
	return false;
}

void BuildingList::update(Building* b, std::string buildingType) {
	if (b->getBuildingType() == CASTLE) { b = new Castle(bl.size()); }
	else if (b->getBuildingType() == TOWNCENTER) { b = new Towncenter(bl.size()); }
	b->setx(x);
	b->sety(y);
	b->setCol(col);
	b->setRow(row);
	addBuilding(b);
	std::cout << b->getRow() << "," << b->getCol() << "\n";
	std::cout << b->getRow() - b->getRowHeight() << "," << b->getCol() - b->getColWidth() << "\n";
	for (int row_ = b->getRow(); row_ >= b->getRow() - b->getRowHeight(); row_--) {
		for (int col_ = b->getCol(); col_ >= b->getCol() - b->getColWidth(); col_--) {
			tm->setOccupied(row_, col_);
		}
	}
}

void BuildingList::render() {
	if (bl.empty() == false) {
		for (int i = 0; i < bl.size(); i++) {
			al_draw_bitmap(bl[i]->getBaseImg() , bl[i]->getx(), bl[i]->gety(), 0);
		}
	}
}

void BuildingList::placingBuilding(Building* b, float x, float y) {
	ALLEGRO_BITMAP* bitmap = b->getBaseImg();
	if (checkPlacingBounds(b)) { al_draw_tinted_bitmap(bitmap, al_map_rgb(240, 128, 128), x, y, 0); }
	else { al_draw_bitmap(bitmap, x, y, 0); }
}