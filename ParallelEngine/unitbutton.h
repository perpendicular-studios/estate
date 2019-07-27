#ifndef UNIT_BUTTON_H
#define UNIT_BUTTON_H
#include "button.h"
#include "entity.h"
#include "player.h"
class UnitButton : public Button {
public:
	UnitButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, ALLEGRO_FONT* fontType,
		ALLEGRO_COLOR fontColor, std::string text, bool visible, MenuState returnState, Entity* target, Player* player);
private:
	Player* player;
	Entity* target;
	void render() override;
	void onClick() override;
};

#endif UNIT_BUTTON_H