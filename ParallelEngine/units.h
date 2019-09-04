#ifndef UNITS_H
#define UNITS_H
#include "entity.h"
#include "player.h"
class Peasant : public Entity {
public:
	Peasant(TileMap* tm, Player * player, int tileCost, int food, int gold, int stone, int wood, int x, int y);
	Entity* clone() const override;
	void update() override;
	void render() override;
	void drawEntityWindow() override;
private:
	float time;
	float harvestCooldown;
	ALLEGRO_TIMER* harvestTimer;
	Player* player;
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