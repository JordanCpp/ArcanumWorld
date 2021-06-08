#include "ObjectManager.h"

ObjectManager::ObjectManager(ResourceManager* SourceManager, XmlManager* XmlManagerSource, Allocator* AllocatorSource):
	reader("", XmlReader::FromString),
	manager(SourceManager),
	xml_manager(XmlManagerSource),
	allocator(AllocatorSource)
{
}

void ObjectManager::Clear()
{
	allocator->Reset();
}

Critter* ObjectManager::GetCritter(const std::string& Name)
{
	Critter* object = new(allocator->Alloc(sizeof(Critter))) Critter(xml_manager->GetTile(Name), manager);

	return object;
}

Tile* ObjectManager::GetTile(const std::string& Name)
{
	Tile * object = new(allocator->Alloc(sizeof(Tile))) Tile(xml_manager->GetTile(Name), manager);

	return object;
}