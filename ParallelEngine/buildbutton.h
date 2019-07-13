#ifndef BUILDBUTTON_H
#define BUILDBUTTON_H

#include "button.h"
#include "building.h"
#include "buildinglist.h"
#include "menustates.h"

class BuildButton : public Button {
public:
	BuildButton(float x1, float y1, float x2, float y2, ALLEGRO_COLOR backgroundColor, ALLEGRO_FONT* fontType,
		ALLEGRO_COLOR fontColor, std::string text, Building* returnBuilding_);

	Building* getBuilding() { return returnBuilding; }
	
	//variables
	Building* returnBuilding;
};

#endif 