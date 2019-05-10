#include "player.h"
Player::Player(ALLEGRO_BITMAP * img, float pos_x, float pos_y, float sp) : Entity(img, pos_x, pos_y), speed(sp) {
	animation = new Animation(img, 64, 64, 5, 8, 0, 196);
}

void Player::render() {
	animation->render(x, y);
}

void Player::update(ALLEGRO_KEYBOARD_STATE & ks) {
	animation->update();
	if (al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		moveRight();
	}

	if (al_key_down(&ks, ALLEGRO_KEY_LEFT)) {
		moveLeft();
	}
}