#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>
#include "entity.h"

class Player : public Entity {
public:
	Player(TileMap * tm);
	void render() override;
	void update(ALLEGRO_KEYBOARD_STATE & ks) override;
	void setSprinting(bool b) { sprinting = b; }

	enum Direction { RIGHT, LEFT, FRONT, BACK };
private:
	bool sprinting = false;
	Direction direction;
};
#endif