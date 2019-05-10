#include "player.h"
Player::Player(ALLEGRO_BITMAP * img, float pos_x, float pos_y) : Entity(img, pos_x, pos_y) {
	speed = 2;

	animationSet = new AnimationSet();
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 1, 0, 0), "idle_front");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 1, 0, 41), "idle_left");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 1, 0, 82), "idle_back");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 1, 0, 123), "idle_right");

	animationSet->addAnimation(new Animation(img, 38, 41, 5, 10, 0, 164), "walk_front");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 10, 0, 205), "walk_left");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 10, 0, 246), "walk_back");
	animationSet->addAnimation(new Animation(img, 38, 41, 5, 10, 0, 287), "walk_right");

	animationSet->addAnimation(new Animation(img, 38, 41, 2, 10, 0, 164), "sprint_front");
	animationSet->addAnimation(new Animation(img, 38, 41, 2, 10, 0, 205), "sprint_left");
	animationSet->addAnimation(new Animation(img, 38, 41, 2, 10, 0, 246), "sprint_back");
	animationSet->addAnimation(new Animation(img, 38, 41, 2, 10, 0, 287), "sprint_right");


	animationSet->setAnimation("idle_front");
	direction = FRONT;
}

void Player::render() {
	animationSet->getCurrentAnimation()->render(x, y);
}

void Player::update(ALLEGRO_KEYBOARD_STATE & ks) {
	animationSet->getCurrentAnimation()->update();
	speed = sprinting ? 4 : 2;

	if (al_key_down(&ks, ALLEGRO_KEY_D)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveRight();
		animationSet->setAnimation(sprinting ? "sprint_right" : "walk_right");
		direction = RIGHT;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_A)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveLeft();
		animationSet->setAnimation(sprinting ? "sprint_left" : "walk_left");
		direction = LEFT;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_W)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveUp();
		animationSet->setAnimation(sprinting ? "sprint_back" : "walk_back");
		direction = BACK;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_S)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveDown();
		animationSet->setAnimation(sprinting ? "sprint_front" : "walk_front");
		direction = FRONT;
	}

	
	
	if (!al_key_down(&ks, ALLEGRO_KEY_A) && 
		!al_key_down(&ks, ALLEGRO_KEY_D) &&
		!al_key_down(&ks, ALLEGRO_KEY_W) &&
		!al_key_down(&ks, ALLEGRO_KEY_S)) {

		switch (direction) {
		case LEFT:
			animationSet->setAnimation("idle_left");
			break;
		case RIGHT:
			animationSet->setAnimation("idle_right");
			break;
		case FRONT:
			animationSet->setAnimation("idle_front");
			break;
		case BACK:
			animationSet->setAnimation("idle_back");
			break;
		}
	}
}