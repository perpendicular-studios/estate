#include "inventory.h"

void Inventory::addResource(Resource res) {
	switch (res.getResourceType()) {
	case FOOD:
		food += res.getYield();
	case WOOD:
		wood += res.getYield();
	case STONE:
		stone += res.getYield();
	case MISC:
		auto it = inventory.find(res.getName());
		if (it == inventory.end()) {
			inventory[res.getName()] = res;
			inventory[res.getName()].addOne();
		}
		else {
			inventory[res.getName()].addOne();
		}
	}
}

void Inventory::removeResource(Resource res, int quantity) {
	switch (res.getResourceType()) {
	case FOOD:
		food -= quantity;
	case WOOD:
		wood -= quantity;
	case STONE:
		stone -= quantity;
	case MISC:
		auto it = inventory.find(res.getName());
		if (it == inventory.end()) {
			// the player does not have the required MISC resource, throw an error TODO
		}
		else {
			inventory[res.getName()].subOne();
			if (inventory[res.getName()].getQuantity() == 0) inventory.erase(res.getName());
		}
	}
}