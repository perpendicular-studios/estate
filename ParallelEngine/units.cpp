#include "units.h"

//peasant
Peasant::Peasant(TileMap* tm, Player* player_, int tileCost, int food, int gold, int stone, int wood, int x, int y) : 
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("peasant"), x, y), player(player_) {
	entityTypeString = "Peasant";
	currHp = maxHp = 50;
	harvestCooldown = 1.0;
	atk = 5;
	def = 1;
}

Entity* Peasant::clone() const {
	return new Peasant(*this);
}

void Peasant::update() {
	time += 1.0;
	// add items to inventory if the peasant is on a resource tile
	if (time / 60 >= harvestCooldown) {
		if (tm->isResource(row, col)) {
			player->addTileToInventory(tm->getTile(row, col));
		}
		time = 0;
	}
}

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
	currHp = maxHp = 100;
	atk = 15;
	def = 5;
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

//merchant
Merchant::Merchant(TileMap* tm, int tileCost, int food, int gold, int stone, int wood, int x, int y) :
	Entity(tm, tileCost, food, gold, stone, wood, AssetLoader::manager->getImage("merchant"), x, y) {
	entityTypeString = "Merchant";
	currHp = maxHp = 50;
	atk = 5;
	def = 1;
}

Entity* Merchant::clone() const {
	return new Merchant(*this);
}

void Merchant::update() {}

void Merchant::render() {
	al_draw_bitmap(img, x, y, 0);
}

void Merchant::drawEntityWindow() {
	drawEntityWindowBackground();
}