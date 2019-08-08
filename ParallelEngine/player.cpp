#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (Entity * e : entities) {
		const GeneralResource* tileResource = (const GeneralResource*)allResource[e->getTileID()];
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

Entity* Player::entityInTile(Vector2i clickCoord) {
	for (Entity* e : entities) {
		if (e->getrow() == clickCoord.y && e->getcol() == clickCoord.x)
		{
			std::cout << "I got clicked on " << std::endl;
			return e;
		}
	}
	return NULL;
}

void Player::renderEntities() {
	for (Entity* e : entities) {
		e->render();
	}
}

void Player::addEntity(Entity* e) {
	entities.push_back(e);
}