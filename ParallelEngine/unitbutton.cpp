#include "unitbutton.h"
UnitButton::UnitButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, Entity* target_, Player* player_, Building* building_) : Button(x1, y1, x2, y2, bitmap, visible, DEFAULTSTATE), 
	target(target_), player(player_), building(building_) {}

void UnitButton::render() {
	al_draw_bitmap(bitmap, x1, y1, 0);
	ALLEGRO_BITMAP* entityImg = target->getImage();
	al_draw_scaled_bitmap(entityImg, 0, 0, al_get_bitmap_width(entityImg), al_get_bitmap_height(entityImg), x1 + 4, y1 + 4, x2 - x1 - 8, y2 - y1 - 8, 0);
}

void UnitButton::onClick() {
	if (player->buyEntity(target)) {
		if (building != nullptr) {
			target->setPosition(building->getx(), building->gety());
		}
		player->addEntity(target);
	}
}