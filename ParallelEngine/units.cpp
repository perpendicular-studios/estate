#include "units.h"
Peasant::Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y) : 
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("peasant"), x, y) {}

Entity* Peasant::clone() const {
	return new Peasant(*this);
}
void Peasant::update() {}
void Peasant::render() {
	Vector2f coords(tm->isoToScreen(x, y));
	al_draw_bitmap(img, coords.x, coords.y, 0);
}