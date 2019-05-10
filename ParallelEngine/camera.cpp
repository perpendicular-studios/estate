#include "camera.h"
#include <cmath>

Camera::~Camera() {}

Camera::Camera(int w, int h, float sp) {
	size.x = w;
	size.y = h;
	
	speed = sp;
	if (speed < 0) speed = 0;
	if (speed > 1) speed = 1;
}

void Camera::move(int x, int y) {
	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::moveCenter(int x, int y) {
	x -= (size.x / 2);
	y -= (size.y / 2);

	position.x = (float)x;
	position.y = (float)y;
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::setTarget(int x, int y) {
	target.x = (float)x;
	target.y = (float)y;
}

void Camera::setCenter(int x, int y) {
	x -= (size.x / 2);
	y -= (size.y / 2);

	target.x = (float)x;
	target.y = (float)y;
}

void Camera::update() {
	float x, y, d;
	float dx, dy, v;
	x = (float)(target.x - position.x);
	y = (float)(target.y - position.y);

	if ((x*x + y*y) <= 1) {
		position.x = target.x;
		position.y = target.y;
	}
	else {
		d = sqrt(x*x + y * y);
		v = (d * speed) / 60;
		if (v < 1.0f) v = 1.0f;

		dx = x * (v / d);
		dy = y * (v / d);

		position.x += dx;
		position.y += dy;
	}
}

IntRect Camera::getTileBounds(int tileSize) {
	int x = (int)(position.x / tileSize);
	int y = (int)(position.y / tileSize);

	int w = (int)(size.x / tileSize + 2);
	int h = (int)(size.y / tileSize + 2);
	
	if (x % tileSize != 0) w++;
	if (y % tileSize != 0) h++;

	return IntRect(x, y, w, h);
}