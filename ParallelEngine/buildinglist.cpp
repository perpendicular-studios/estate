#include "buildinglist.h"
#include <vector>

void BuildingList::addBuilding(Building* buildingObject) {
	//buildings are sorted by render order (0 is rendered first)
	if (bl.empty()) { bl.push_back(buildingObject); }
	else {
		int i = 0;
		bool reachEnd = false;
		while (isBuilding1InFront(buildingObject, bl[i]) && !reachEnd) {
			i++;
			if (i == bl.size()) {
				reachEnd = true;
				i--;
			}
		}
		if (reachEnd) {
			std::cout << "Insert at end \n";
			bl.insert(bl.end(), buildingObject);
		}
		else {
			std::cout << "Inserting at " << i << "\n";
			bl.insert(bl.begin() + i, buildingObject);
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

void BuildingList::update(Building* b) {
	if (b->getBuildingType() == CASTLE) { b = new Castle(bl.size()); }
	else if (b->getBuildingType() == TOWNCENTER) { b = new Towncenter(bl.size()); }
	else if(b->getBuildingType() == MARKET) { b = new Market(bl.size()); }
	b->setx(x);
	b->sety(y);
	b->setCol(col);
	b->setRow(row);
	addBuilding(b);
	currBuilding = b;
	std::cout << b->getRow() << "," << b->getCol() << "\n";
	std::cout << b->getRow() - b->getRowHeight() << "," << b->getCol() - b->getColWidth() << "\n";
	for (int row_ = b->getRow(); row_ >= b->getRow() - b->getRowHeight(); row_--) {
		for (int col_ = b->getCol(); col_ >= b->getCol() - b->getColWidth(); col_--) {
			tm->setOccupyStatus(row_, col_, 1);
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

bool BuildingList::isBuilding1InFront(Building* b1, Building* b2) {
	//check if b1 is in front of b2
	if (b1->getRow() <= b2->getTopRow()) { return false; }
	else if (b2->getRow() <= b1->getTopRow()) { return true; }

	if (b1->getCol() <= b2->getTopCol()) { return false; }
	else if (b2->getCol() <= b1->getTopCol()) { return true; }
}

Building* BuildingList::isTileInBounds(int currCol, int currRow) {
	Building* returnBuilding = NULL;
	for (int i = 0; i < bl.size(); i++) {
		if (currCol <= bl[i]->getCol() && currCol >= bl[i]->getTopCol() && currRow <= bl[i]->getRow() && currRow >= bl[i]->getTopRow()) {
			returnBuilding = bl[i];
		}
	}
	return returnBuilding;
}