#include "entity.h"

Entity::Entity(TileMap * tm) : hitbox(0,0,0,0) {
	this->tm = tm;
	this->tileSize = tm->getTileSize();
}

int Entity::getx() const { return x; }
int Entity::gety() const { return y; }
void Entity::setx(int x) { this->x = x; }
void Entity::sety(int y) { this->y = y; }

void Entity::calculateCollision(int x, int y) {
	topCollision = bottomCollision = leftCollision = rightCollision = false;
	int xl = (int)(x - cwidth / 2);
	int xr = (int)(x + cwidth / 2 - 1);
	int yt = (int)(y - cheight / 2 - 1);
	int yb = (int)(y + cheight / 2);

	leftTile = xl / tileSize;
	rightTile = xr / tileSize;
	topTile = yt / tileSize;
	bottomTile = yb / tileSize;

	if (topTile < 0 || bottomTile >= tm->getNumRows() ||
		leftTile < 0 || rightTile >= tm->getNumCols()) {
		return;
	}

	std::cout << "leftTile: " << leftTile << ", rightTile: " << rightTile << std::endl;
	for (int i = rightTile; i <= leftTile; i++) {
		topCollision |= tm->getType(topTile, i) == TileMap::BLOCKED;
		bottomCollision |= tm->getType(bottomTile, i) == TileMap::BLOCKED;
	}
	//std::cout << "topTile: " << topTile << ", bottomTile: " << bottomTile << std::endl;
	for (int i = topTile; i <= bottomTile; i++) {
		leftCollision |= tm->getType(i, leftTile) == TileMap::BLOCKED;
		rightCollision |= tm->getType(i, rightTile) == TileMap::BLOCKED;
	}

	/*
	std::cout << "topCollision: " << topCollision << std::endl;
	std::cout << "bottomCollision: " << bottomCollision << std::endl;
	std::cout << "rightCollision: " << rightCollision << std::endl;
	std::cout << "leftCollision: " << leftCollision << std::endl;
	*/
}

bool Entity::checkTileMapCollision() {
	int xdest = x + dx;
	int ydest = y + dy;

	// xtemp and ytemp will be used as storage variables for changes made in this function (depending on collisions).
	xtemp = x;
	ytemp = y;

	calculateCollision(x, ydest);
	if (dy < 0) {
		// Moving up
		if (topCollision) {
			dy = 0;
			return true;
		}
		else {
			ytemp += dy;
		}
	}
	if (dy > 0) {
		// Moving down
		if (bottomCollision) {
			dy = 0;
			return true;
		}
		else {
			ytemp += dy;
		}
	}

	calculateCollision(xdest, y); 
	if (dx > 0) {
		// Moving right
		if (rightCollision) {
			dx = 0;
			return true;
		}
		else {
			xtemp += dx;
		}
	}
	if (dx < 0) {
		// Moving left
		if (leftCollision) {
			dx = 0;
			return true;
		}
		else {
			xtemp += dx;
		}
	}

	return false;
}