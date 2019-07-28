#include "entity.h"
Entity::Entity(TileMap* tm_, int tileCost_, int food_, int gold_, int stone_, int wood_, ALLEGRO_BITMAP* img_) : tm(tm_), tileCost(tileCost_), food(food_), gold(gold_), stone(stone_), wood(wood_), img(img_) {
	xdest = ydest = 0;
	x = 492;
	y = 253;
}

Entity::~Entity() {
	delete tm;
}

void Entity::renderRadius() {
	// render radius of movement
	int topBound, bottomBound, leftBound, rightBound;
	topBound = bottomBound = leftBound = rightBound = tileCost;
	
	// start from far extreme of bound, decrement going back to center, if one tile is found that is not blocked, stop. 

	// top
	for (int i = tileCost; i > 0; i--) {
		if (tm->getType(getrow() - i, getcol()) == TileMap::BLOCKED) topBound--;
		if (tm->getType(getrow() - i, getcol()) == TileMap::NORMAL) break;
	}

	// bottom
	for (int i = tileCost; i > 0; i--) {
		if (tm->getType(getrow() + i, getcol()) == TileMap::BLOCKED) bottomBound--;
		if (tm->getType(getrow() + i, getcol()) == TileMap::NORMAL) break;
	}


	// right
	for (int i = tileCost; i > 0; i--) {
		if (tm->getType(getrow(), getcol() + i) == TileMap::BLOCKED) rightBound--;
		if (tm->getType(getrow(), getcol() + i) == TileMap::NORMAL) break;
	}


	// left
	for (int i = tileCost; i > 0; i--) {
		if (tm->getType(getrow(), getcol() - i) == TileMap::BLOCKED) leftBound--;
		if (tm->getType(getrow(), getcol() - i) == TileMap::NORMAL) break;
	}

	// render bounds
	for (int row = topBound; row < bottomBound; row++) {
		for (int col = leftBound; col < rightBound; col++) {
			Vector2f screenCoord = tm->isoToScreen(row, col);
			al_draw_bitmap(AssetLoader::manager->getImage("radius"), screenCoord.x, screenCoord.y, 0);
		}
	}

}