#ifndef CASTLE_H
#define CASTLE_H
#include "entity.h"

class Castle : public Entity {
public:
	Castle(TileMap * tm, int x, int y, std::string key) : Entity(tm, key) {
		this->x = x;
		this->y = y;
		img = AssetLoader::manager->getImage("castle");
	}

	void update() override;
	void render() override;
private:
	int x, y;
	ALLEGRO_BITMAP * img;
};

#endif