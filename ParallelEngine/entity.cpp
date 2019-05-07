#include "entity.h"
ALLEGRO_BITMAP* Entity::getImage() const { return image; }
float Entity::gety() const { return y; }
float Entity::getx() const { return x; }

void Entity::setx(float pos_x) { x = pos_x; }
void Entity::sety(float pos_y) { y = pos_y; }