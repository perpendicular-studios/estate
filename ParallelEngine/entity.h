#ifndef ENTITY_H
#define ENTITY_H

#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class Entity {
public:
	Entity(ALLEGRO_BITMAP* img, float pos_x, float pos_y, float sp) : image(img), x(pos_x), y(pos_y), speed(sp) {}
	ALLEGRO_BITMAP* getImage() const;
	float getx() const;
	float gety() const;
	void setx(float x);
	void sety(float y);
	void moveRight();
	void moveLeft();
private:
	ALLEGRO_BITMAP* image;
	float x, y;
	float speed;
};

#endif ENTITY_H