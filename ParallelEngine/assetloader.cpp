#include "assetloader.h"
#include <iostream>

AssetManager* AssetLoader::manager = new AssetManager();

AssetLoader::AssetLoader() {
	std::cout << "Loading Images..." << std::endl;
	manager->loadImage("images/tileset.png", "tileset");
	manager->loadImage("images/hover.png", "hover", true);
	manager->loadImage("images/radius.png", "radius", true);
	manager->loadImage("images/castle.png", "castle", true);
	manager->loadImage("images/town_center.png", "towncenter", true);
	manager->loadImage("images/market.png", "market", false);
	manager->loadImage("images/basicbutton.png", "basicbutton", false);
	manager->loadImage("images/productionbg.png", "productionbg", false);
	manager->loadImage("images/flagbg.png", "flagbg", false);
	manager->loadImage("images/x.png", "x", false);
	manager->loadImage("images/miscbg.png", "miscbg", false);
	manager->loadImage("images/resources_menu.png", "resources_menu", false);
	manager->loadImage("images/peasant.png", "peasant", false);
	manager->loadImage("images/merchant.png", "merchant", false);
	manager->loadImage("images/knight.png","knight", false);
	manager->loadImage("images/popup.png", "popup", false);

	// load resource sprites
	manager->loadImage("images/resources/tile_wheat.png", "tile_wheat", false);
	manager->loadImage("images/resources/tile_rice.png", "tile_rice", false);
	manager->loadImage("images/resources/tile_iron.png", "tile_iron", false);
	manager->loadImage("images/resources/iron.png", "iron", false);
	manager->loadImage("images/resources/cloth.png", "cloth", false);
	std::cout << "Done Loading Images..." << std::endl;

}