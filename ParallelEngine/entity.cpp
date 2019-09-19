#include "entity.h"
#include <queue>
Entity::Entity(TileMap* tm_, int tileCost_, int food_, int gold_, int stone_, int wood_, ALLEGRO_BITMAP* img_, int x_, int y_) : tm(tm_), tileCost(tileCost_), food(food_), gold(gold_), stone(stone_), wood(wood_), img(img_), x(x_), y(y_) {
	xdest = ydest = 0;
}

bool Entity::operator==(Entity* rhs) {
	if (rhs == NULL)
		return false;
	return (this->getrow() == rhs->getrow() && this->getcol() == rhs->getcol());
}

Entity::~Entity() {

}

void Entity::loseHp(int hp_) {
	currHp -= hp_;
}

void Entity::drawHP() {
	float percentage = ((float)currHp / maxHp);
	percentage = percentage * 36;
	al_draw_filled_rectangle(x + tm->getTileWidth() / 4, y - 6, x + tm->getTileWidth() / 4 + 36, y - 2, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(x + tm->getTileWidth() / 4 + 2, y - 5, x + tm->getTileWidth() / 4 + percentage - 2, y - 3, al_map_rgb(0, 255, 0));
}

void Entity::drawEntityHP() {
	float percentage = ((float)currHp / maxHp);
	percentage = percentage * 75;
	al_draw_filled_rectangle(Var::WIDTH - 190, 255, Var::WIDTH - 95, 270, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(Var::WIDTH - 185, 260, Var::WIDTH - 175 + percentage, 265, al_map_rgb(0, 255, 0));

	char buffer1[100];
	snprintf(buffer1, 33, "%d%s%d", currHp, "/", maxHp);
	const char* fractionHp = buffer1;
	al_draw_text(basic_font15, al_map_rgb(0, 0, 0), Var::WIDTH - 90, 255, 0, fractionHp);
}

void Entity::drawEntityWindowBackground() {
	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 145, 175, ALLEGRO_ALIGN_CENTRE, entityTypeString.c_str());
	al_draw_scaled_bitmap(img, 0, 0, al_get_bitmap_width(img), al_get_bitmap_height(img), Var::WIDTH - 170, 200, 50, 50, 0);
	drawEntityHP();
}

// Input: row, col
// TODO: Decide what to do when tile isn't found
bool Entity::setPosition(int row, int col) {
	// building
	Vector2f mapCoords = findNearestUnoccupiedPos(row, col);
	if (mapCoords.x != -1) {
		std::cout << "Found a spot at row: " << mapCoords.x << ", col: " << mapCoords.y << std::endl;
		tm->setOccupyStatus(getrow(), getcol(), TileMap::NORMAL);
		tm->setOccupyStatus(mapCoords.x, mapCoords.y, TileMap::BLOCKED);

		Vector2f screenCoords = tm->isoToScreen(mapCoords.x, mapCoords.y);
		std::cout << "Found a spot at x: " << screenCoords.x << ", y: " << screenCoords.y << std::endl;
		x = screenCoords.x;
		y = screenCoords.y;
		this->col = mapCoords.y;
		this->row = mapCoords.x;
		return true;
	}
	else {
		std::cout << "Unable to find a spot" << std::endl;
		return false;
	}
}

// BFS
// Takes in row, col
// Returns row, col
// TODO:: Do something when nearest unoccupied tile isn't found
// Intentional bug turned feature incoming
Vector2f Entity::findNearestUnoccupiedPos(int x_, int y_) {
	int iterNum = 1;
	std::queue<Vector2f> q;
	Vector2f currPos = Vector2f(x_, y_);
	q.push(currPos);
	while (!q.empty()) {
		currPos = q.front();
		q.pop();
		iterNum++;
		if (currPos.x < 0 && currPos.y < 0 && currPos.x >= tm->getNumRows() && currPos.y >= tm->getNumCols()) {
			continue;
		}
		if (!tm->isResource(currPos.x, currPos.y) && tm->checkOccupied(currPos.x, currPos.y) || tm->getType(currPos.x, currPos.y) == TileMap::BLOCKED) { // getTile needs to be changed to getType
			q.push(Vector2f(currPos.x, currPos.y + 1));
			q.push(Vector2f(currPos.x + 1, currPos.y + 1));
			q.push(Vector2f(currPos.x + 1, currPos.y));
			q.push(Vector2f(currPos.x + 1, currPos.y - 1));
			q.push(Vector2f(currPos.x, currPos.y - 1));
			q.push(Vector2f(currPos.x - 1, currPos.y - 1));
			q.push(Vector2f(currPos.x - 1, currPos.y));
			q.push(Vector2f(currPos.x - 1, currPos.y + 1));
		}
		else {
			return currPos;
		}
		if (iterNum >= 250) { // fail safe iteration number
			return Vector2f(-1, -1); // Cannot find appropriate position
		}
	}
}

// input: row, col
void Entity::moveTo(int row, int col) {
	// TODO: Animation
	setPosition(row, col);
}