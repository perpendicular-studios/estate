#include "entity.h"

Entity::Entity(TileMap * tm) {
	this->tm = tm;
}

void Entity::updateLocation() {
	if (tilesCanMove <= 0) return;

	if (xdest < x) {
		dx = -moveSpeed;
	}
	if (xdest > x) {
		dx = moveSpeed;
	}
	if(xdest == x) {
		dx = 0;
	}

	if (ydest < y) {
		dy = -moveSpeed;
	}
	if (ydest > y) {
		dy = moveSpeed;
	}
	if(ydest == y) {
		dy = 0;
	}


	if (x != xdest) {
		x += dx;
	}
	if (y != ydest) {
		y += dy;
	}
}