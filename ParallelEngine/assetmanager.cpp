#include "assetmanager.h"
AssetManager::AssetManager() {
	al_init_image_addon();
}

void AssetManager::loadImage(std::string path, std::string key, bool transparency) {
	ALLEGRO_BITMAP* bitmap = NULL;
	bitmap = al_load_bitmap(path.c_str());
	if (transparency) al_convert_mask_to_alpha(bitmap, al_map_rgb(0, 0, 0));
	assert(bitmap != NULL);
	images[key] = bitmap;
}

ALLEGRO_BITMAP* AssetManager::getImage(std::string key) {
	return images[key];
}

void AssetManager::destroy_images() {
	for (auto itr = images.begin(); itr != images.end(); itr++) {
		al_destroy_bitmap(itr->second);
		images.erase(itr);
	}
}