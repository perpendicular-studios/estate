#include "camera.h"
#include <iostream>
Camera::Camera(float x_, float y_, int width_, int height_) : x(x_), y(y_), width(width_), height(height_) {
	moveSpeed = 5;
}

void Camera::update() {
	if (up) {
		dy = -moveSpeed;
	}
	else if (down) {
		dy = moveSpeed;
	}
	else {
		dy = 0;
	}

	if (right) {
		dx = moveSpeed;
	}
	else if (left) {
		dx = -moveSpeed;
	}
	else {
		dx = 0;
	}

	x += dx;
	y += dy;
}