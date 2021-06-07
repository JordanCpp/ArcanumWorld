#ifndef _ObjectManager_h_
#define _ObjectManager_h_

#include <vector>
#include "../Game/Critter.h"
#include "../Game/Tile.h"

class ObjectManager
{
public:
	ObjectManager(ResourceManager* SourceManager);
	Critter* GetCritter(const std::string& Name);
	Tile* GetTile();
private:
	XmlReader reader;
	ResourceManager* manager;
	std::vector<Critter> critters;
	std::vector<Tile> tiles;
};

#endif