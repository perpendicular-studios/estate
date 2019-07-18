#ifndef UNITS_H
#define UNITS_H
#include "entity.h"
class Peasant : public Entity {
public:
	Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood) : Entity(tm, tileCost, food, gold, stone, wood) {
		img = AssetLoader::manager->getImage("peasant");
	}
	void update() override;
	void render() override;
private:
	ALLEGRO_BITMAP* img; // TODO: change to animation set
};


#endif