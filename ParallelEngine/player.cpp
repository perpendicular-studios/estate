#include "player.h"
Player::Player(ALLEGRO_BITMAP * img, float pos_x, float pos_y, float sp) : Entity(img, pos_x, pos_y), speed(sp) {
	animationSet = new AnimationSet();
	animationSet->addAnimation(new Animation(img, 64, 64, 5, 9, 0, 0), "walk_back");
	animationSet->addAnimation(new Animation(img, 64, 64, 5, 9, 0, 64), "walk_left");
	animationSet->addAnimation(new Animation(img, 64, 64, 5, 9, 0, 128), "walk_front");
	animationSet->addAnimation(new Animation(img, 64, 64, 5, 9, 0, 196), "walk_right");
	animationSet->setAnimation("walk_front");
}

void Player::render() {
	animationSet->getCurrentAnimation()->render(x, y);
}

void Player::update(ALLEGRO_KEYBOARD_STATE & ks) {
	animationSet->getCurrentAnimation()->update();
	if (al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		moveRight();
		animationSet->setAnimation("walk_right");
	}

	if (al_key_down(&ks, ALLEGRO_KEY_LEFT)) {
		moveLeft();
		animationSet->setAnimation("walk_left");
	}
	
	if (!al_key_down(&ks, ALLEGRO_KEY_LEFT) && !al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		animationSet->setAnimation("walk_front");
	}
}