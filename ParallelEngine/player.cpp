#include "player.h"
Player::Player(ALLEGRO_BITMAP * img, float pos_x, float pos_y, float sp) : Entity(img, pos_x, pos_y), speed(sp) {}

void Player::render() {
	al_draw_bitmap(getImage(), getx(), gety(), 0);
}

void Player::update(ALLEGRO_KEYBOARD_STATE & ks) {
	if (al_key_down(&ks, ALLEGRO_KEY_RIGHT)) {
		moveRight();
	}

	if (al_key_down(&ks, ALLEGRO_KEY_LEFT)) {
		moveLeft();
	}
}