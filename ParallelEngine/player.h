#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>
#include "entity.h"
#include "animationset.h"

class Player : public Entity {
public:
	Player(ALLEGRO_BITMAP* img, float pos_x, float pos_y);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks) override;
	void moveRight() { x += speed; }
	void moveLeft() { x -= speed; }
	void moveUp() { y -= speed; }
	void moveDown() { y += speed; }
	
	enum Direction { RIGHT, LEFT, FRONT, BACK };
private:
	float speed;
	bool sprinting = false;
	Direction direction;
	AnimationSet * animationSet;
};
#endif