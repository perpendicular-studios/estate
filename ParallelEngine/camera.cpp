#include "camera.h"
#include <iostream>

Camera::Camera(int x, int y, int width, int height, int xmin, int xmax, int ymin, int ymax) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->xmax = xmax;
	this->ymax = ymax;
	this->xmin = xmin;
	this->ymin = ymin;
	this->scale = 1.0f;

	this->maxZoom = 10;
}

Camera::~Camera() {}

void Camera::update(int x, int y) {
	this->x = -(Var::WIDTH / 2) + (x + width / 2);
	this->y = -(Var::HEIGHT / 2) + (y + height / 2);

	if (this->x < xmin) this->x = xmin;
	if (this->y < ymin) this->y = ymin;

	if (this->x > xmax - Var::WIDTH) this->x = xmax - Var::WIDTH;
	if (this->y > ymax - Var::HEIGHT) this->y = ymax - Var::HEIGHT;
	
}
