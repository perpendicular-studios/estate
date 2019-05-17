#include "player.h"
Player::Player(TileMap * tm) : Entity(tm) {
	moveSpeed = 2;
	width = height = 32;
	x = y = 64;
	xdest = x;
	ydest = y;

	ALLEGRO_BITMAP * img = AssetLoader::manager->getImage("player");
	animationSet.addAnimation(new Animation(img, width, height, 5, 1, 32, 0), "idle_front");
	animationSet.addAnimation(new Animation(img, width, height, 5, 1, 32, 32), "idle_left");
	animationSet.addAnimation(new Animation(img, width, height, 5, 1, 32, 64), "idle_right");
	animationSet.addAnimation(new Animation(img, width, height, 5, 1, 32, 96), "idle_back");

	animationSet.addAnimation(new Animation(img, width, height, 5, 3, 0, 0), "walk_front");
	animationSet.addAnimation(new Animation(img, width, height, 5, 3, 0, 32), "walk_left");
	animationSet.addAnimation(new Animation(img, width, height, 5, 3, 0, 64), "walk_right");
	animationSet.addAnimation(new Animation(img, width, height, 5, 3, 0, 96), "walk_back");

	animationSet.addAnimation(new Animation(img, width, height, 3, 3, 0, 0), "sprint_front");
	animationSet.addAnimation(new Animation(img, width, height, 3, 3, 0, 32), "sprint_left");
	animationSet.addAnimation(new Animation(img, width, height, 3, 3, 0, 64), "sprint_right");
	animationSet.addAnimation(new Animation(img, width, height, 3, 3, 0, 96), "sprint_back");

	animationSet.setAnimation("idle_front");
	direction = FRONT;
}

void Player::render() {
	animationSet.getCurrentAnimation()->render(x, y);
	updateLocation();
}

void Player::update() {
	animationSet.getCurrentAnimation()->update();
	//std::cout << xdest << ", " << ydest << std::endl;
}