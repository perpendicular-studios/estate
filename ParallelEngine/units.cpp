#include "units.h"

//peasant
Peasant::Peasant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y) : 
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("peasant"), x, y) {
	entityTypeString = "Peasant";
	currHp = hp = 50;
}

Entity* Peasant::clone() const {
	return new Peasant(*this);
}

void Peasant::update() {}

void Peasant::render() {
	al_draw_bitmap(img, x, y, 0);
}

void Peasant::drawEntityWindow() {
	drawEntityWindowBackground();
}

//knight
Knight::Knight(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y) :
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("knight"), x, y) {
	entityTypeString = "Knight";
	currHp = hp = 100;
}

Entity* Knight::clone() const {
	return new Knight(*this);
}

void Knight::update() {}

void Knight::render() {
	al_draw_bitmap(img, x, y, 0);
}

void Knight::drawEntityWindow() {
	drawEntityWindowBackground();
}