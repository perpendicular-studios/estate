#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>
#include "entity.h"

class Player : public Entity {
public:
	Player(ALLEGRO_BITMAP* img, float pos_x, float pos_y, float sp);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks) override;
	void moveRight() { setx(getx() + speed); }
	void moveLeft() { setx(getx() - speed); }
private:
	float speed;
};
#endif