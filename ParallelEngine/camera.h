#ifndef CAMERA_H
#define CAMERA_H

#include "vec2.h"
#include "rectangle.h"

class Camera {
public:
	Camera(int w, int h, float sp);
	~Camera();

	void move(int x, int y);
	void moveCenter(int x, int y);

	void setTarget(int x, int y);
	void setCenter(int x, int y);

	void update();

	Vector2i getPosition() { return Vector2i((int)(position.x), (int)(position.y)); }
	Vector2i getTileOffset(int tileSize) { return Vector2i((int)(position.x) % tileSize, (int)(position.y) % tileSize); }
	IntRect getTileBounds(int tileSize);

private:
	Vector2f position;
	Vector2f target;
	Vector2i size;
	float speed;
};

#endif CAMERA_H