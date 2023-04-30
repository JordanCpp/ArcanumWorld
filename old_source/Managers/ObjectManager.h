#ifndef _ObjectManager_h_
#define _ObjectManager_h_ 

#include "XmlManager.h"
#include "../Allocators/Allocator.h"
#include "../Managers/ScriptManager.h"
#include "../Objects/Tile.h"

class ScriptManager;

class ObjectManager
{
public:
	ObjectManager(XmlManager* XmlManagerSource, Allocator* AllocatorSource, ScriptManager* ScriptManagerSource, ImageManager* ImageManagerSource);
	Critter* GetCritter(const std::string& XmlName);
	ScriptCritter* GetScriptCritter(const std::string Name);
	Tile* GetTile(const std::string& XmlName);
private:
	XmlManager* xml_manager;
	Allocator* allocator;
	ScriptManager* script_manager;
	ImageManager* image_manager;
};

#endif