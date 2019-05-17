#ifndef CAMERA_H
#define CAMERA_H

#include "var.h"

class Camera {
public:
	Camera(int x, int y, int width, int height, int xmin, int xmax, int ymin, int ymax);
	~Camera();
	void update(int x, int y);

	int getx() { return x; }
	int gety() { return y; }
private:
	int x, y;
	int width, height;
	int xmax, ymax, xmin, ymin;
};


#endif CAMERA_H