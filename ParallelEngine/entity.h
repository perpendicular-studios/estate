#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "animation.h"

class Entity {
public:
	Entity(ALLEGRO_BITMAP* img, float pos_x, float pos_y) : image(img), x(pos_x), y(pos_y) {}
	ALLEGRO_BITMAP* getImage() const;
	float getx() const;
	float gety() const;
	void setx(float x);
	void sety(float y);

	virtual void render() = 0;
	virtual void update(ALLEGRO_KEYBOARD_STATE & ks) = 0;
protected:
	ALLEGRO_BITMAP* image;
	float x, y;
	Animation * animation;
};

#endif ENTITY_H