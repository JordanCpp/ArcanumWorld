#ifndef _ObjectManager_h_
#define _ObjectManager_h_

#include <vector>
#include "../Game/Critter.h"
#include "../Game/Tile.h"
#include "../Allocators/LinearAllocator.h"

class ObjectManager
{
public:
	ObjectManager(ResourceManager* SourceManager, size_t Bytes);
	void Clear();
	Critter* GetCritter(const std::string& Name);
	Tile* GetTile(const std::string& Name);
private:
	XmlReader reader;
	ResourceManager* manager;
	LinearAllocator allocator;
};

#endif