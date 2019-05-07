#include "camera.h"

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

}
