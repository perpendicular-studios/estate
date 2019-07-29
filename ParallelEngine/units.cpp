#include "units.h"
Peasant::Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y) : 
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("peasant"), x, y) {}
void Peasant::update() {}
void Peasant::render() {
	al_draw_bitmap(img, x, y, 0);
}