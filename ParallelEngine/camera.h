#ifndef CAMERA_H
#define CAMERA_H
#include "var.h"
#include "tilemap.h"

class Camera {
public:
	Camera(float x, float y, std::shared_ptr<TileMap> map_);
	void update();
	void setLeft(bool b) { left = b; }
	void setRight(bool b) { right = b; }
	void setUp(bool b) { up = b; }
	void setDown(bool b) { down = b; }
	int getx() { return x; }
	int gety() { return y; }
private:
	float x, y;
	int dx, dy;
	int moveSpeed;
	bool left = false, right = false, up = false, down = false;
	int mapHeightX, mapHeightY, mapLeftBound, mapRightBound;
	int offset, tileWidth;
	std::shared_ptr<TileMap> map;
};


#endif