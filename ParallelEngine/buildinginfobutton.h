#ifndef BUILDINGINFOBUTTON_H
#define BUILDINGINFOBUTTON_H

#include "button.h"
#include "building.h"
#include "menustates.h"

class BuildingInfoButton : public Button {
public:
	BuildingInfoButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
		ALLEGRO_COLOR fontColor, std::string text, bool visible_, Building* returnBuilding_);

	Building* getBuilding() { return returnBuilding; }

	//variables
	Building* returnBuilding;
};

#endif 