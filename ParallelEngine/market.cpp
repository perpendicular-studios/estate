#include "market.h"

Market::Market(int marketID_) : Building(AssetLoader::manager->getImage("market"), 240, 195), marketID(marketID_) {
	stone = 300;
	gold = 0;
	wood = 300;
	food = 0;
	width = 240;
	height = 195;
	buildingType = MARKET;
	buildingTypeString = "Market";
	currHp = hp = 500;
}

void Market::drawBuildingWindow() {
	drawBuildingWindowBackground();
}