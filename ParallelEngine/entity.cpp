#include "entity.h"
#include <queue>
Entity::Entity(TileMap* tm_, int tileCost_, int food_, int gold_, int stone_, int wood_, ALLEGRO_BITMAP* img_, int x_, int y_) : tm(tm_), tileCost(tileCost_), food(food_), gold(gold_), stone(stone_), wood(wood_), img(img_), x(x_), y(y_) {
	xdest = ydest = 0;
}

Entity::~Entity() {
}

// Input: row, col
// TODO: Decide what to do when tile isn't found
bool Entity::setPosition(int x_, int y_) {
	Vector2f mapCoords = findNearestUnoccupiedPos(x_, y_);
	std::cout << "Found a spot at row: " << mapCoords.x << ", col: " << mapCoords.y << std::endl;
	tm->setOccupyStatus(getrow(), getcol(), TileMap::NORMAL);
	tm->setOccupyStatus(mapCoords.x, mapCoords.y, TileMap::BLOCKED);

	Vector2f screenCoords = tm->isoToScreen(mapCoords.x, mapCoords.y);
	x = screenCoords.x;
	y = screenCoords.y;
	return true;
}

// BFS
// Takes in row, col
// Returns row, col
// TODO:: Do something when nearest unoccupied tile isn't found
// Intentional bug turned feature incoming
Vector2f Entity::findNearestUnoccupiedPos(int x_, int y_) {
	std::queue<Vector2f> q;
	Vector2f currPos = Vector2f(x_, y_);
	q.push(currPos);
	while (!q.empty()) {
		currPos = q.front();
		q.pop();
		if (currPos.x < 0 && currPos.y < 0 && currPos.x >= tm->getNumRows() && currPos.y >= tm->getNumCols()) {
			continue;
		}
		if (tm->checkOccupied(currPos.x, currPos.y) || tm->getType(currPos.x, currPos.y) == TileMap::BLOCKED) { // getTile needs to be changed to getType
			q.push(Vector2f(currPos.x, currPos.y + 1));
			q.push(Vector2f(currPos.x + 1, currPos.y + 1));
			q.push(Vector2f(currPos.x + 1, currPos.y));
			q.push(Vector2f(currPos.x + 1, currPos.y - 1));
			q.push(Vector2f(currPos.x, currPos.y - 1));
			q.push(Vector2f(currPos.x - 1, currPos.y - 1));
			q.push(Vector2f(currPos.x - 1, currPos.y));
			q.push(Vector2f(currPos.x - 1, currPos.y + 1));
		}
		else {
			return currPos;
		}

	}
}

// TODO: Not working
// Goal: Return the center x and y of the tile
//Vector2f Entity::getTileCenter() {
//	Vector2f rowCol = tm->screenToIso(x, y);
//	return tm->isoToScreen(rowCol.x, rowCol.y);
//}

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

void Entity::moveTo(int x, int y) {

}