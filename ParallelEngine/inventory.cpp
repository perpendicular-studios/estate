#include "inventory.h"

void Inventory::addGeneralResource(const GeneralResource * res) {
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
	}
}

void Inventory::addMiscResource(const MiscResource* res, int quantity) {
	for (int i = 0; i < quantity; i++) {
		inventory[res->getName()].push_back(res);
	}
}

void Inventory::removeGeneralResource(ResourceType res, int quantity) {
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
	}
}

void Inventory::removeMiscResource(const MiscResource* res, int quantity) {
	if (this->hasItem(res->getName())) {
		auto begin = inventory[res->getName()].begin();
			inventory[res->getName()].erase(begin, begin + quantity);
	}
}

std::vector<std::vector<const MiscResource*>> Inventory::getMiscResources() {
	std::vector<std::vector<const MiscResource*>> result;
	for (std::pair<std::string, std::vector<const MiscResource*>> e : inventory) {
		if (e.second.size() > 0) {
			result.push_back(e.second);
		}
	}
	return result;
}
