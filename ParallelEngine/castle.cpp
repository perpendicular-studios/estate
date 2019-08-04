#include "castle.h"

Castle::Castle(int castleID_) : Building(AssetLoader::manager->getImage("castle"), 607, 447), castleID(castleID_) {
	stone = 500;
	gold = 200;
	wood = 0;
	food = 0;
	width = 400;
	height = 352;
	buildingType = CASTLE;
	buildingTypeString = "Castle";
	currHp = hp = 500;
	currGarrison = 0;
	maxGarrison = 50;
}

void Castle::drawBuildingWindow() {
	drawBuildingWindowBackground();

	char buffer1[100];
	snprintf(buffer1, 33, "%s%d%s%d", "Garrison: ", currGarrison, "/", maxGarrison);
	const char* garrisonChar = buffer1;
	al_draw_text(basic_font15, al_map_rgb(0, 0, 0), Var::WIDTH - 290, 275, 0, garrisonChar);
}