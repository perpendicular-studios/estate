#include "unitbutton.h"
UnitButton::UnitButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
	ALLEGRO_COLOR fontColor, std::string text, bool visible, MenuState returnState, Entity* target_, Player* player_) : Button(x1, y1, x2, y2, bitmap, fontType, fontColor, text, visible, returnState), 
	target(target_), player(player_) {}

void UnitButton::render() {
	al_draw_bitmap(bitmap, x1, y1, 0);
	ALLEGRO_BITMAP* entityImg = target->getImage();
	al_draw_scaled_bitmap(entityImg, 0, 0, al_get_bitmap_width(entityImg), al_get_bitmap_height(entityImg), x1, y1, x2 - x1, y2 - y1, 0);
	al_draw_text(fontType, fontColor, fontX, fontY, 0, text.c_str());
}

void UnitButton::onClick() {
	if (player->buyEntity(target)) {
		player->addEntity(target);
	}
}