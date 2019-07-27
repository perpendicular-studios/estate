#include "towncenter.h"

Towncenter::Towncenter(int towncenterID_) : Building(AssetLoader::manager->getImage("towncenter"), 255, 287), towncenterID(towncenterID_) {
	stone = 300;
	gold = 0;
	wood = 300;
	food = 0;
	width = 255;
	height = 287;
	buildingType = TOWNCENTER;
}