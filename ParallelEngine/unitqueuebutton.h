#ifndef UNITQUEUEBUTTON_H
#define UNITQUEUEBUTTON_H
#include "button.h"
#include "entity.h"
#include "player.h"

class UnitQueueButton : public Button {
public:
	UnitQueueButton(float x1, float y1, float x2, float y2, ALLEGRO_BITMAP* bitmap, bool visible, Player* player, IGM* igm_, int num);
	void setEntity(Entity* e_) { e = e_; }
	int getNum() { return num; }
private:
	Player* player;
	Entity* e;
	IGM* igm;
	void render() override;
	void onClick() override;
	int num;
};

#endif