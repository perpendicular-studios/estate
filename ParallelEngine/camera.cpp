#include "camera.h"
#include <iostream>
#include <algorithm>

Camera::Camera(float x_, float y_, std::shared_ptr<TileMap> map_) : x(x_), y(y_), map(map_){
	moveSpeed = 10; //even numbers only or else camera will jitter
	dx = dy = 0;
	tileWidth = map->getTileWidth();
	mapHeightY = std::min(map->getNumCols(), map->getNumRows()) * map->getTileHeight() + abs(map->getNumCols() - map->getNumRows()) * map->getTileHeight() /2 - Var::HEIGHT;
	mapHeightX = std::max(map->getNumCols(), map->getNumRows()) * tileWidth / 2 - std::min(map->getNumCols(), map->getNumRows()) * tileWidth / 2 - Var::WIDTH / 2 + tileWidth / 2;
	mapRightBound = map->getNumCols() * map->getTileWidth() / 2 - Var::WIDTH + map->getTileWidth() / 2;
	mapLeftBound = -map->getNumRows() * map->getTileWidth() / 2;
	offset = - Var::WIDTH /4 + tileWidth /4 ;
	
}

void Camera::update() {
	dx = dy = 0;

	//exceptions
	if (up && down) { dy = 0; }
	else if (left && right) { dx = 0; }
	
	//up
	else if (up && y >= 0 && y > x/2 + Var::WIDTH /4 - tileWidth /4 && y > -x / 2 + offset) {
		dy = -moveSpeed;
	}
	else if (up && y >= 0  && y <= x/2 + Var::WIDTH /4 - tileWidth /4 && y > -x / 2 + offset) {
		dy = -moveSpeed / 2;
		dx = -moveSpeed;
	}
	else if (up && y >= 0 && y > x/2 + Var::WIDTH /4 - tileWidth /4 && y <= -x / 2 + offset) {
		dy = -moveSpeed / 2;
		dx = moveSpeed;
	}	
	
	//down 
	else if (down && y <= mapHeightY && y < -x/2 + mapHeightY + mapHeightX /2 && y < x/2 + mapHeightY - mapHeightX /2) {
		dy = moveSpeed;
	}
	else if (down && y <= mapHeightY && y >= -x/2 + mapHeightY + mapHeightX /2 && y < x/2 + mapHeightY - mapHeightX /2) {
		dy = moveSpeed / 2;
		dx = -moveSpeed; 
	}
	else if (down && y <= mapHeightY && y < -x/2 + mapHeightY + mapHeightX /2 && y >= x/2 + mapHeightY - mapHeightX /2) {
		dy = moveSpeed / 2;
		dx = moveSpeed;
	}

	//right
	else if (right && x <= mapRightBound && y > x / 2 + Var::WIDTH / 4 - tileWidth / 4 && y < -x / 2 + mapHeightY + mapHeightX / 2) {
		dx = moveSpeed;
	}
	else if (right && x <= mapRightBound && y <= x / 2 + Var::WIDTH / 4 - tileWidth / 4 && y < -x / 2 + mapHeightY + mapHeightX / 2) {
		dy = moveSpeed / 2;
		dx = moveSpeed;
	}
	else if (right && x <= mapRightBound && y > x / 2 + Var::WIDTH / 4 - tileWidth / 4 && y >= -x / 2 + mapHeightY + mapHeightX / 2) {
		dy = -moveSpeed / 2;
		dx = moveSpeed;
	} 

	//left
	else if (left && x >= mapLeftBound && y > -x / 2 + offset && y < x / 2 + mapHeightY - mapHeightX / 2) {
		dx = -moveSpeed;
	}
	else if (left && x >= mapLeftBound && y <= -x / 2 + offset && y < x / 2 + mapHeightY - mapHeightX / 2) {
		dy = moveSpeed / 2;
		dx = -moveSpeed;
	}
	else if (left && x >= mapLeftBound && y > -x / 2 + offset && y >= x / 2 + mapHeightY - mapHeightX / 2) {
		dy = -moveSpeed / 2;
		dx = -moveSpeed;
	}

	x += dx;
	y += dy; 
}