#include "inventory.h"

void Inventory::addResource(const Resource * res) {
	switch (res->getResourceType()) {
	case FOOD:
		food += res->getYield();
		break;
	case WOOD:
		wood += res->getYield();
		break;
	case STONE:
		stone += res->getYield();
		break;
	case GOLD:
		gold += res->getYield();
		break;
	case MISC:
		inventory[res->getName()].push_back(res);
		break;
	}
}

void Inventory::removeResource(ResourceType res, int quantity) {
	switch (res) {
	case FOOD:
		(food >= quantity) ? food -= quantity : throw "Not enough food!";
		break;
	case WOOD:
		(wood >= quantity) ? wood -= quantity : throw "Not enough wood!";
		break;
	case STONE:
		(stone >= quantity) ? stone -= quantity : throw "Not enough stone!";
		break;
	case GOLD:
		(gold >= quantity) ? gold -= quantity : throw "Not enough gold!";
		break;
	default:
		throw "Cant remove MISC item without a given MISC item object";
		break;
	}
}

void Inventory::removeResource(const Resource * res, int quantity) {
	switch (res->getResourceType()) {
	case MISC:
		if (inventory[res->getName()].size() >= quantity) {
			auto begin = inventory[res->getName()].begin();
			inventory[res->getName()].erase(begin, begin + quantity);
		}
		else {
			throw "Not enough " + res->getName() + "!";
		}
		break;
	default:
		throw "item in inventory shouldn't be FOOD, WOOD, GOLD, STONE";
		break;
	}
}