#include "entity.h"
Entity::Entity(TileMap* tm_) : tm(tm_) {
	x = 0; y = 0;
}

Entity::~Entity() {
	delete tm;
}
