#include "animation.h"
#include <iostream>
Animation::Animation(ALLEGRO_BITMAP * img, int frameWidth, int frameHeight, int frameDelay, int maxFrames, int x, int y) : 
	image(img), width(frameWidth), height(frameHeight), delay(frameDelay), numFrames(maxFrames) {
	
	currentFrame = 0;
	frameCount = 0;
	this->x = x;
	this->y = y;
}

Animation::~Animation() {}

void Animation::update() {
	if (delay <= 0) return;
	frameCount++;
	if (frameCount >= delay) {
		frameCount = 0;
		currentFrame++;
		if (currentFrame >= numFrames) currentFrame = 0;
	}
}

void Animation::render(int x, int y) {
	al_draw_bitmap_region(image, this->x + currentFrame * width, this->y, width, height, x, y, 0);
}

