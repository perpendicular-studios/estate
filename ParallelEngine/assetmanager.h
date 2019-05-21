#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <map>
#include <string>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>

class AssetManager {
public:
	AssetManager();
	void loadImage(std::string path, std::string key) { loadImage(path, key, false); }
	void loadImage(std::string path, std::string key, bool transparency);
	ALLEGRO_BITMAP* getImage(std::string key);
	void destroy_images();
private:
	std::map<std::string, ALLEGRO_BITMAP*> images;
};


#endif