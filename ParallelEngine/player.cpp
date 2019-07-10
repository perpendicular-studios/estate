#include "player.h"

// add resource items from entities standing on resource tiles on the map.
void Player::updateInventory() {
	for (Entity * e : entities) {
		if (e->getTileType() == TileMap::RESOURCE) {
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
}
