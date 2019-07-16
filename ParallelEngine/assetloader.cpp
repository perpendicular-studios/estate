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
	manager->loadImage("images/resourcebg.png", "resourcebg", false);
	manager->loadImage("images/basicbutton.png", "basicbutton", false);
	manager->loadImage("images/productionbg.png", "productionbg", false);
	manager->loadImage("images/flagbg.png", "flagbg", false);
	manager->loadImage("images/x.png", "x", false);
	manager->loadImage("images/miscbg.png", "miscbg", false);
	std::cout << "Done Loading Images..." << std::endl;

}