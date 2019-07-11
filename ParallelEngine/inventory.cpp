#include "inventory.h"

void Inventory::addResource(const Resource * res) {
	switch (res->getResourceType()) {
	case FOOD:
		food += res->getYield();
	case WOOD:
		wood += res->getYield();
	case STONE:
		stone += res->getYield();
	case GOLD:
		gold += res->getYield();
	case MISC:
		inventory[res->getName()].push_back(res);
	}
}

void Inventory::removeResource(ResourceType res, int quantity) {
	switch (res) {
	case FOOD:
		(food >= quantity) ? food -= quantity : throw "Not enough food!";
	case WOOD:
		(wood >= quantity) ? wood -= quantity : throw "Not enough wood!";
	case STONE:
		(stone >= quantity) ? stone -= quantity : throw "Not enough stone!";
	case GOLD:
		(gold >= quantity) ? gold -= quantity : throw "Not enough gold!";
	default:
		throw "Cant remove MISC item without a given MISC item object";
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
	default:
		throw "item in inventory shouldn't be FOOD, WOOD, GOLD, STONE";
	}
}