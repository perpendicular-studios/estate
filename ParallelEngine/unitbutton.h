#ifndef UNITBUTTON_H
#define UNITBUTTON_H
#include "button.h"
#include "entity.h"
#include "player.h"
class UnitButton : public Button {
public:
	UnitButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, Entity* target, Player* player, IGM* igm_);
private:
	Player* player;
	Entity* target;
	IGM* igm;
	void render() override;
	void onClick() override;
};

#endif UNITBUTTON_H