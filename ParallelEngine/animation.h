#ifndef ANIMATION_H
#define ANIMATION_H

#include <allegro5/allegro5.h>
class Animation {
public:
	Animation(ALLEGRO_BITMAP * img, int frameWidth, int frameHeight, int delay, int numFrames, int x, int y);
	~Animation();
	void update();
	void render(int x, int y);
private:
	ALLEGRO_BITMAP * image;
	int numFrames;
	int currentFrame;
	int frameCount;
	int delay;
	int width, height;
	int x, y;
};

#endif