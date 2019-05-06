#include "assetloader.h"
#include <iostream>

AssetManager* AssetLoader::manager = new AssetManager();

AssetLoader::AssetLoader() {
	std::cout << "Loading Images..." << std::endl;
	manager->loadImage("Image.jpg", "image");
	std::cout << "Done Loading Images..." << std::endl;

}