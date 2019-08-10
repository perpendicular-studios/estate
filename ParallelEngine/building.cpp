#include "building.h"
#include "player.h"

Building::Building(ALLEGRO_BITMAP* bitmap_, int width_, int height_) : bitmap(bitmap_), width(width_), height(height_) {
	//for whole number cols and rows
	colWidth = (width + 63) / 64;			
	rowHeight = (height + 63) / 64;
	unitQueueTimer = al_create_timer(0.01);
	al_start_timer(unitQueueTimer);
}

void Building::draw(ALLEGRO_BITMAP* bitmap, float x, float y) {
	al_draw_bitmap(bitmap, x, y, 0);
}

void Building::drawBuildingHP() {
	float percentage = ((float)currHp / hp);
	percentage = percentage * 75;
	al_draw_filled_rectangle(Var::WIDTH - 190, 255, Var::WIDTH - 95, 270, al_map_rgb(0, 0, 0));
	al_draw_filled_rectangle(Var::WIDTH - 185, 260, Var::WIDTH - 175 + percentage, 265, al_map_rgb(0, 255, 0));
	
	char buffer1[100];
	snprintf(buffer1, 33, "%d%s%d", currHp, "/", hp);
	const char* fractionHp = buffer1;
	al_draw_text(basic_font15, al_map_rgb(0, 0, 0), Var::WIDTH - 90, 255, 0, fractionHp);
}

void Building::drawBuildingWindowBackground() {
	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 145, 175, ALLEGRO_ALIGN_CENTRE, buildingTypeString.c_str());
	al_draw_scaled_bitmap(bitmap, 0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), Var::WIDTH - 170, 200, 50, 50, 0);
	drawBuildingHP();
	drawUnitQueue();

	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 290, 300, 0, "Units");
	al_draw_text(basic_font20, al_map_rgb(0, 0, 0), Var::WIDTH - 290, 450, 0, "Queue");
}

void Building::drawUnitQueue() {
	if (!unitQueue.empty()) {
		int time = al_get_timer_count(unitQueueTimer) - startTime;
		float percentage = ((float)time / 1000);
		int percentInt = ((float)time / 1000 * 100);
		percentage = percentage * 80;
		al_draw_filled_rectangle(Var::WIDTH - 190, 495, Var::WIDTH - 95, 510, al_map_rgb(0, 0, 0));
		al_draw_filled_rectangle(Var::WIDTH - 185, 500, Var::WIDTH - 180 + percentage, 505, al_map_rgb(0, 255, 0));
		
		char buffer1[100];
		snprintf(buffer1, 33, "%d%s", percentInt, "%");
		const char* percentString = buffer1;
		al_draw_text(basic_font15, al_map_rgb(0, 0, 0), Var::WIDTH - 75, 490, 0, percentString);
		al_draw_text(basic_font15, al_map_rgb(0, 0, 0), Var::WIDTH - 190, 480, 0, currEntity->getEntityTypeString().c_str());
	}
}

void Building::addUnit(Entity* e) {
	if (unitQueue.empty()) { 
		startTime = al_get_timer_count(unitQueueTimer); 
		currEntity = e;
	}
	if (unitQueue.size() >= 11) {
		std::cout << "Cannot add unit, too many in queue.\n";
	}
	else {
		unitQueue.push_back(e);
	}
}

void Building::cancelUnit(int num) {
	unitQueue.erase(unitQueue.begin() + num);
	if (num == 0 && !unitQueue.empty()) { startTime = al_get_timer_count(unitQueueTimer); }
	if (!unitQueue.empty()) { currEntity = unitQueue.front(); }
}

void Building::produceUnits() {
	if (al_get_timer_count(unitQueueTimer) - startTime >=  1000) { isSpawn = true; }
	if (!unitQueue.empty() && isSpawn) {
		newEntity = unitQueue.front();
		unitQueue.erase(unitQueue.begin() + 0);
		if (newEntity->setPosition(getRow(), getCol())) {
			std::cout << "Troops spawned" << std::endl;
			p->addEntity(newEntity);
		}
		else {
			std::cout << "Could not spawn troop" << std::endl;
			delete newEntity;
		}
		startTime = al_get_timer_count(unitQueueTimer);
		if (!unitQueue.empty()) { currEntity = unitQueue.front(); }
	}
	isSpawn = false;
}

