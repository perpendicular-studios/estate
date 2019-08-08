#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (auto& e : entities) {
		const GeneralResource* tileResource = WHEAT;
		switch (e.second->getTileID()) {
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
			tileResource = TREE;
			break;
		case 10: //light_gold_ore
			tileResource = LIGHT_GOLD_ORE;
			break;
		case 11: //heavy_gold_ore
			tileResource = HEAVY_GOLD_ORE;
			break;
		case 12: //light_stone_ore
			tileResource = LIGHT_STONE_ORE;
			break;
		case 13: //heavy_stone_ore
			tileResource = HEAVY_STONE_ORE;
			break;
		default:
			tileResource = NULL;
			break;
		}
		inventory->addGeneralResource(tileResource);
	}
}

//temporary! remove when entity movement is implemented
void Player::addTileToInventory(int tileID) {
	const GeneralResource* tileResource;
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
		tileResource = TREE;
		break;
	case 10: //light_gold_ore
		tileResource = LIGHT_GOLD_ORE;
		break;
	case 11: //heavy_gold_ore
		tileResource = HEAVY_GOLD_ORE;
		break;
	case 12: //light_stone_ore
		tileResource = LIGHT_STONE_ORE;
		break;
	case 13: //heavy_stone_ore
		tileResource = HEAVY_STONE_ORE;
		break;
	default:
		tileResource = NULL;
		break;
	}

	if(tileResource != NULL) inventory->addGeneralResource(tileResource);
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