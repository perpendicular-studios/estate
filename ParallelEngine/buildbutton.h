#ifndef BUILDBUTTON_H
#define BUILDBUTTON_H

#include "button.h"
#include "building.h"
#include "buildinglist.h"
#include "menustates.h"
#include "player.h"
#include "building.h"

class BuildButton : public Button {
public:
	BuildButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
		ALLEGRO_COLOR fontColor, std::string text, bool visible_, Building* target, Player* player);

	Building* getBuilding() { return target; }

	void render() override;
	void onClick() override;

private:
	Player* player;
	Building* target;
};

#endif 