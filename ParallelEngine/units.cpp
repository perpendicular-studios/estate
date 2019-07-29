#include "units.h"
Peasant::Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood) : Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("peasant")) {}
void Peasant::update() {}
void Peasant::render() {
	al_draw_bitmap(img, x, y, 0);
}