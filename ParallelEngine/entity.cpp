#include "entity.h"

Entity::Entity(TileMap * tm) : hitbox(0,0,0,0) {
	this->tm = tm;
}

int Entity::getx() const { return x; }
int Entity::gety() const { return y; }
void Entity::setx(int x) { this->x = x; }
void Entity::sety(int y) { this->y = y; }

bool Entity::checkTileMapCollision() {
	return false;
}