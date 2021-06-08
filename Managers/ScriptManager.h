#ifndef _ScriptManager_h_
#define _ScriptManager_h_

#include <string>
#include "../Game/Script.h"

class ScriptManager
{
public:
	ScriptManager(Engine* EngineSource, Allocator* AllocatorSource);
	Script * GetScript(const std::string & Name);
private:
	Script* NewScript();
	Engine* engine;
	Allocator* allocator;
};

#endif