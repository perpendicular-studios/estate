#ifndef UNITS_H
#define UNITS_H
#include "entity.h"
class Peasant : public Entity {
public:
	Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, ALLEGRO_BITMAP* img) : Entity(tm, tileCost, food, gold, stone, wood, img) {}
	void update() override;
	void render() override;
};


#endif