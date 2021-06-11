#include "ObjectManager.h"

ObjectManager::ObjectManager(XmlManager* XmlManagerSource, Allocator* AllocatorSource, ScriptManager* ScriptManagerSource, ImageManager* ImageManagerSource):
	xml_manager(XmlManagerSource),
	allocator(AllocatorSource),
	script_manager(ScriptManagerSource),
	image_manager(ImageManagerSource)
{
}

Critter* ObjectManager::GetCritter(const std::string& XmlName)
{
	Critter* critter = new (allocator->Alloc(sizeof(Critter))) Critter(xml_manager->GetCritter(XmlName));

	return critter;
}

ScriptCritter* ObjectManager::GetScriptCritter(const std::string Name)
{
	ScriptCritter* script = script_manager->GetCritter(Name);

	return script;
}

Tile* ObjectManager::GetTile(const std::string& XmlName)
{
	Tile* tile = new (allocator->Alloc(sizeof(Tile))) Tile(xml_manager->GetTile(XmlName), image_manager);

	return tile;
}