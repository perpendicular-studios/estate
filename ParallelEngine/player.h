#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>
#include "entity.h"

class Player : public Entity {
public:
	Player(TileMap * tm);
	void render() override;
	void update() override;

	enum Direction { RIGHT, LEFT, FRONT, BACK };
private:
	Direction direction;
};
#endif