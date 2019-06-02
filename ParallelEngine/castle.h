#ifndef CASTLE_H
#define CASTLE_H

#include "building.h"
#include "assetloader.h"

class Castle : public Building {
public:
	Castle(std::shared_ptr<TileMap> tm_, std::string index_) : Building(tm_, index_) { img = AssetLoader::manager->getImage("castle"); }
	void update(ALLEGRO_KEYBOARD_STATE & ks, float mouseX, float mouseY) override;
	void render() override;
};
#endif