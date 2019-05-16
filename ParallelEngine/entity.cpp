#include "entity.h"

Entity::Entity(TileMap * tm) {
	this->tm = tm;
	this->tileSize = tm->getTileSize();
}

int Entity::getx() const { return x; }
int Entity::gety() const { return y; }
void Entity::setx(int x) { this->x = x; }
void Entity::sety(int y) { this->y = y; }