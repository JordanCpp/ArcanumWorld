#include "ObjectManager.h"

ObjectManager::ObjectManager(ResourceManager* SourceManager, XmlManager* XmlManagerSource, size_t Bytes):
	reader("", XmlReader::FromString),
	manager(SourceManager),
	xml_manager(XmlManagerSource),
	allocator(Bytes)
{
}

void ObjectManager::Clear()
{
	allocator.Reset();
}

Critter* ObjectManager::GetCritter(const std::string& Name)
{
	Critter* object = new(allocator.Alloc(sizeof(Critter))) Critter(xml_manager->GetXmlTile(Name), manager);

	return object;
}

Tile* ObjectManager::GetTile(const std::string& Name)
{
	Tile * object = new(allocator.Alloc(sizeof(Tile))) Tile(xml_manager->GetXmlTile(Name), manager);

	return object;
}
