#include "assetloader.h"
#include <iostream>

AssetManager* AssetLoader::manager = new AssetManager();

AssetLoader::AssetLoader() {
	std::cout << "Loading Images..." << std::endl;
	manager->loadImage("images/Image.jpg", "image");
	manager->loadImage("images/player.png", "player");
	manager->loadImage("images/tileset.png", "tileset");
	std::cout << "Done Loading Images..." << std::endl;

}