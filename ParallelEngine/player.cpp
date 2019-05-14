#include "player.h"
Player::Player(TileMap * tm) : Entity(tm) {
	v = 2;
	cwidth = cheight = 20;
	width = height = 32;
	hitbox = Rectangle<int>(x, y, cwidth, cheight);

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
	animationSet.getCurrentAnimation()->update();
	v = sprinting ? 4 : 2;

	if (al_key_down(&ks, ALLEGRO_KEY_D)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveRight();
		animationSet.setAnimation(sprinting ? "sprint_right" : "walk_right");
		direction = RIGHT;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_A)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveLeft();
		animationSet.setAnimation(sprinting ? "sprint_left" : "walk_left");
		direction = LEFT;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_W)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveUp();
		animationSet.setAnimation(sprinting ? "sprint_back" : "walk_back");
		direction = BACK;
	}

	if (al_key_down(&ks, ALLEGRO_KEY_S)) {
		sprinting = al_key_down(&ks, ALLEGRO_KEY_SPACE);
		moveDown();
		animationSet.setAnimation(sprinting ? "sprint_front" : "walk_front");
		direction = FRONT;
	}
	
	if (!al_key_down(&ks, ALLEGRO_KEY_A) && 
		!al_key_down(&ks, ALLEGRO_KEY_D) &&
		!al_key_down(&ks, ALLEGRO_KEY_W) &&
		!al_key_down(&ks, ALLEGRO_KEY_S)) {

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