#include "entity.h"

Entity::Entity(std::shared_ptr<TileMap> tm_, int id_) : tm(tm_), id(id_) {
	moveSpeed = 4;
}

void Entity::move(int xdest, int ydest) {
	if (x != xdest) {
		if (x < xdest) dx = moveSpeed;
		else dx = -moveSpeed;

		x += dx;
	}
	if (y != ydest) {
		if (y < ydest) dx = moveSpeed;
		else dy = -moveSpeed;

		y += dy;
	}
}