#include "player.h"
Player::Player(TileMap * tm) : Entity(tm) {
	moveSpeed = 2;
	cwidth = cheight = 20;
	width = height = 32;
	x = y = 50;

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
}

void Player::update(ALLEGRO_KEYBOARD_STATE & ks) {
	setLeft(al_key_down(&ks, ALLEGRO_KEY_A));
	setRight(al_key_down(&ks, ALLEGRO_KEY_D));
	setUp(al_key_down(&ks, ALLEGRO_KEY_W));
	setDown(al_key_down(&ks, ALLEGRO_KEY_S));
	setSprinting(al_key_down(&ks, ALLEGRO_KEY_SPACE));

	animationSet.getCurrentAnimation()->update();
	moveSpeed = sprinting ? 4 : 2;

	if (right) {
		animationSet.setAnimation(sprinting ? "sprint_right" : "walk_right");
		direction = RIGHT;
		dx = moveSpeed;
	}
	else if (left) {
		animationSet.setAnimation(sprinting ? "sprint_left" : "walk_left");
		direction = LEFT;
		dx = -moveSpeed;
	}
	else {
		dx = 0;
	}

	if (up) {
		animationSet.setAnimation(sprinting ? "sprint_back" : "walk_back");
		direction = BACK;
		dy = -moveSpeed;
	}
	else if (down) {
		animationSet.setAnimation(sprinting ? "sprint_front" : "walk_front");
		direction = FRONT;
		dy = moveSpeed;
	}
	else { 
		dy = 0; 
	}

	// move the player and check for collision.
	checkTileMapCollision();
	x = xtemp;
	y = ytemp;
	
	if (!left && !right && !up && !down) {
		switch (direction) {
		case LEFT:
			animationSet.setAnimation("idle_left");
			break;
		case RIGHT:
			animationSet.setAnimation("idle_right");
			break;
		case FRONT:
			animationSet.setAnimation("idle_front");
			break;
		case BACK:
			animationSet.setAnimation("idle_back");
			break;
		}
	}
}