#ifndef UNITS_H
#define UNITS_H
#include "entity.h"
class Peasant : public Entity {
public:
	Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y);
	Entity* clone() const override;
	void update() override;
	void render() override;
	void drawEntityWindow() override;
};

class Knight : public Entity {
public:
	Knight(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y);
	Entity* clone() const override;
	void update() override;
	void render() override;
	void drawEntityWindow() override;
};

#endif