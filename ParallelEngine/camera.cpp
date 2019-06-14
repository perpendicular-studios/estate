#include "camera.h"
#include <iostream>
Camera::Camera(float x_, float y_) : x(x_), y(y_) {
	moveSpeed = 5;
	dx = dy = 0;
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