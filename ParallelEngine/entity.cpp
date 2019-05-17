#include "entity.h"

Entity::Entity(TileMap * tm) {
	this->tm = tm;
	this->tileSize = tm->getTileSize();
}

void Entity::updateLocation() {
	if (xdest < x) {
		dx = -moveSpeed;
	}
	else if (xdest > x) {
		dx = moveSpeed;
	}
	else {
		dx = 0;
	}

	if (ydest < y) {
		dy = -moveSpeed;
	}
	else if (ydest > y) {
		dy = moveSpeed;
	}
	else {
		dy = 0;
	}

	if (x != xdest) x += dx;
	if (y != ydest) y += dy;
}