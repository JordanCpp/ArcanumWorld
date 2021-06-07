#include "ObjectManager.h"

ObjectManager::ObjectManager(ResourceManager* SourceManager, size_t Bytes):
	reader("", XmlReader::FromString),
	manager(SourceManager),
	allocator(Bytes)
{
}

Critter* ObjectManager::GetCritter(const std::string& Name)
{
	Critter* object = new(allocator.Alloc(sizeof(Critter))) Critter(manager->GetXmlTile(Name), manager);

	return object;
}

Tile* ObjectManager::GetTile(const std::string& Name)
{
	Tile * object = new(allocator.Alloc(sizeof(Tile))) Tile(manager->GetXmlTile(Name), manager);

	return object;
}
