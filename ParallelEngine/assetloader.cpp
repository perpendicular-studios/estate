#include "assetloader.h"
#include <iostream>

AssetManager* AssetLoader::manager = new AssetManager();

AssetLoader::AssetLoader() {
	std::cout << "Loading Images..." << std::endl;
	manager->loadImage("images/tileset.png", "tileset");
	manager->loadImage("images/hover.png", "hover");
	manager->loadImage("images/castle.png", "castle", true);
	std::cout << "Done Loading Images..." << std::endl;

}