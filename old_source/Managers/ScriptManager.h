#ifndef _ScriptManager_h_
#define _ScriptManager_h_ 

#include "../Objects/ScriptCritter.h"
#include "../Objects/ScriptLocation.h"
#include "../Objects/ScriptTile.h"
#include "../Allocators/Allocator.h"
#include <string>

class Engine;
class ScriptLocation;

class ScriptManager
{
public:
	ScriptManager(Engine* EngineSource, Allocator* AllocatorSource);
	ScriptCritter* NewCritter();
	ScriptLocation* NewLocation();
	ScriptTile* NewTile();
	ScriptCritter* GetCritter(const std::string& Name);
	ScriptLocation* GetLocation();
	ScriptTile* GetTile();
private:
	Engine* engine;
	Allocator* allocator;
};

#endif