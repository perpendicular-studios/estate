#ifndef PLAYER_H
#define PLAYER_H

#include <allegro5/allegro5.h>
#include "entity.h"

class Player : public Entity {
public:
	Player(TileMap * tm, int x, int y, std::string key);
	void render() override;
	void update() override;

	enum Direction { RIGHT, LEFT, FRONT, BACK };
private:
	Direction direction;
	AnimationSet animationSet;
};
#endif