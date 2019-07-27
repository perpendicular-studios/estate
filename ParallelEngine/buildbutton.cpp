#include "buildbutton.h"
#include "igm.h"

BuildButton::BuildButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, Building* target_, Player* player_, IGM* igm_) :
	Button(x1, y1, x2, y2, bitmap, visible, PLACINGBUILDING), target(target_), player(player_), igm(igm_) {}

void BuildButton::onClick() {
	if (player->buyBuilding(target)) {

	}
	igm->setState(returnState);
}

void BuildButton::render() {
	al_draw_bitmap(bitmap, x1, y1, 0);
	ALLEGRO_BITMAP* buildingImg = target->getBaseImg();
	al_draw_scaled_bitmap(buildingImg, 0, 0, al_get_bitmap_width(buildingImg), al_get_bitmap_height(buildingImg), x1, y1, x2 - x1 - 2, y2 - y1 - 2, 0);
	if (text.length() > 0 && fontType != NULL) {
		al_draw_text(fontType, fontColor, fontX, fontY, 0, text.c_str());
	}
}