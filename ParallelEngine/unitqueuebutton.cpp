#include "unitqueuebutton.h"
#include "igm.h"

UnitQueueButton::UnitQueueButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, Player* player_, IGM* igm_, int num_) : Button(x1, y1, x2, y2, bitmap, visible, BUILDINGINFOSTATE),
player(player_), igm(igm_), num(num_) {}

void UnitQueueButton::render() {
	al_draw_bitmap(bitmap, x1, y1, 0);
	ALLEGRO_BITMAP* entityImg = e->getImage();
	al_draw_scaled_bitmap(entityImg, 0, 0, al_get_bitmap_width(entityImg), al_get_bitmap_height(entityImg), x1 + 4, y1 + 4, 42, 42, 0 );
}

void UnitQueueButton::onClick() {
	igm->getPrevSelectedBuilding()->cancelUnit(num);
	igm->setState(returnState);
}