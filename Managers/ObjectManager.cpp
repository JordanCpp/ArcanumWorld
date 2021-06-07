#include "ObjectManager.h"

ObjectManager::ObjectManager(ResourceManager* SourceManager):
	reader("", XmlReader::FromString),
	manager(SourceManager)
{
	critters.reserve(512);
}

Critter* ObjectManager::GetCritter(const std::string& Name)
{
	Critter object(nullptr, manager);

	critters.push_back(object);

	size_t i = critters.size();

	return &critters[i];
}

Tile* ObjectManager::GetTile()
{
	Tile object;

	tiles.push_back(object);

	size_t i = tiles.size();

	return &tiles[i];
}
