#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (Entity * e : entities) {
		const Resource* tileResource = WHEAT;
		switch (e->getTileID()) {
		case 6: //rice
			tileResource = RICE;
			break;
		case 7: //chicken
			tileResource = CHICKEN;
			break;
		case 8: //mutton
			tileResource = MUTTON;
			break;
		case 9: //light_wood
			tileResource = LIGHT_WOOD;
			break;
		case 10: //heavy_wood
			tileResource = HEAVY_WOOD;
			break;
		case 11: //light_gold_ore
			tileResource = LIGHT_GOLD_ORE;
			break;
		case 12: //heavy_gold_ore
			tileResource = HEAVY_GOLD_ORE;
			break;
		case 13: //light_stone_ore
			tileResource = LIGHT_STONE_ORE;
			break;
		case 14: //heavy_stone_ore
			tileResource = HEAVY_STONE_ORE;
			break;
		case 15: //wool
			tileResource = WOOL;
			break;
		case 16: //iron_ore
			tileResource = IRON_ORE;
			break;
		}
		inventory->addResource(tileResource);
	}
}

void Player::addTileToInventory(int tileID) {
	const Resource* tileResource;
	switch (tileID) {
	case 5:
		tileResource = WHEAT;
	case 6: //rice
		tileResource = RICE;
		break;
	case 7: //chicken
		tileResource = CHICKEN;
		break;
	case 8: //mutton
		tileResource = MUTTON;
		break;
	case 9: //light_wood
		tileResource = LIGHT_WOOD;
		break;
	case 10: //heavy_wood
		tileResource = HEAVY_WOOD;
		break;
	case 11: //light_gold_ore
		tileResource = LIGHT_GOLD_ORE;
		break;
	case 12: //heavy_gold_ore
		tileResource = HEAVY_GOLD_ORE;
		break;
	case 13: //light_stone_ore
		tileResource = LIGHT_STONE_ORE;
		break;
	case 14: //heavy_stone_ore
		tileResource = HEAVY_STONE_ORE;
		break;
	case 15: //wool
		tileResource = WOOL;
		break;
	case 16: //iron_ore
		tileResource = IRON_ORE;
		break;
	default:
		tileResource = NULL;
		break;
	}

	if(tileResource != NULL) inventory->addResource(tileResource);
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
					inventory->removeResource(req.first, req.second);
				}
				catch (char* e) {
					std::cout << e << std::endl;
				}
			}
		}
	}

	try {
		if (foodCost != 0 && getFood() >= foodCost) inventory->removeResource(FOOD, foodCost);
		if (stoneCost != 0 && getStone() >= stoneCost) inventory->removeResource(STONE, stoneCost);
		if (woodCost != 0 && getWood() >= woodCost) inventory->removeResource(WOOD, woodCost);
		if (goldCost != 0 && getGold() >= goldCost) inventory->removeResource(GOLD, goldCost);
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
		if (foodCost != 0 && getFood() >= foodCost) inventory->removeResource(FOOD, foodCost);
		if (stoneCost != 0 && getStone() >= stoneCost) inventory->removeResource(STONE, stoneCost);
		if (woodCost != 0 && getWood() >= woodCost) inventory->removeResource(WOOD, woodCost);
		if (goldCost != 0 && getGold() >= goldCost) inventory->removeResource(GOLD, goldCost);
		success = true;
	}
	catch (char* e) {
		std::cout << e << std::endl;
	}

	return success;

}

Entity* Player::entityInTile(Vector2i clickCoord) {
	for (Entity* e : entities) {
		if (e->getrow() == clickCoord.y && e->getcol() == clickCoord.x) return e;
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