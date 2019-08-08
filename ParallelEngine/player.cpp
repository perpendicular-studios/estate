#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (std::pair<std::pair<int, int>, Entity*> e : entities) {
		const GeneralResource* tileResource = (const GeneralResource*)allResource[e.second->getTileID()];
		inventory->addGeneralResource(tileResource);
	}
}

//temporary! remove when entity movement is implemented
void Player::addTileToInventory(int tileID) {
	const Resource* tileResource = (tileID >= TileMap::NUM_TILES) ? allResource[tileID - TileMap::NUM_TILES] : NULL;
	if (tileResource != NULL) {
		if(tileResource->getType() == Resource::GENERAL) {
			inventory->addGeneralResource((const GeneralResource*)tileResource);
		}
		else {
			inventory->addMiscResource((const MiscResource*)tileResource, 1);
		}
	}
}


bool Player::buyBuilding(Building* building) {
	int foodCost = building->getFoodCost();
	int stoneCost = building->getStoneCost();
	int woodCost = building->getWoodCost();
	int goldCost = building->getGoldCost();

	bool success = false;

	if (building->requiresItems() && inventory->hasItems()) {
		for (auto req : building->getRequiredItems()) {
			if (inventory->hasItem(req.first->getName())) {
				try {
					inventory->removeMiscResource(req.first, req.second);
				}
				catch (char* e) {
					std::cout << e << std::endl;
				}
			}
		}
	}

	try {
		if (foodCost != 0 && getFood() >= foodCost) inventory->removeGeneralResource(FOOD, foodCost);
		if (stoneCost != 0 && getStone() >= stoneCost) inventory->removeGeneralResource(STONE, stoneCost);
		if (woodCost != 0 && getWood() >= woodCost) inventory->removeGeneralResource(WOOD, woodCost);
		if (goldCost != 0 && getGold() >= goldCost) inventory->removeGeneralResource(GOLD, goldCost);
		success = true;
	}
	catch (char* e) {
		std::cout << e << std::endl;
	}

	return success;
}

bool Player::buyEntity(Entity* entity) {
	int foodCost = entity->getFoodCost();
	int stoneCost = entity->getStoneCost();
	int woodCost = entity->getWoodCost();
	int goldCost = entity->getGoldCost();

	bool success = false;
	try {
		if (foodCost != 0 && getFood() >= foodCost) inventory->removeGeneralResource(FOOD, foodCost);
		if (stoneCost != 0 && getStone() >= stoneCost) inventory->removeGeneralResource(STONE, stoneCost);
		if (woodCost != 0 && getWood() >= woodCost) inventory->removeGeneralResource(WOOD, woodCost);
		if (goldCost != 0 && getGold() >= goldCost) inventory->removeGeneralResource(GOLD, goldCost);
		success = true;
	}
	catch (char* e) {
		std::cout << e << std::endl;
	}

	return success;

}

// Input: row, col
Entity* Player::entityInTile(int row, int col) {
	std::pair<int, int> pair(row, col);
	if (entities.find(pair) != entities.end()) {
		std::cout << "I got clicked on " << std::endl;
		return entities.at(pair);
	}
	else
		return NULL;
}

void Player::renderEntities() {
		for (auto& e : entities) {
			e.second->render();
		}
}

void Player::addEntity(Entity* e) {
	std::cout << "Added entity at row: " << e->getrow() << ", col: " << e->getcol() << std::endl;
	std::pair<int, int> coords(e->getrow(), e->getcol());
	entities.insert({ coords, e });
}