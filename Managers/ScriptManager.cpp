#include "ScriptManager.h"
#include "../Scripts/Tester.h"

ScriptManager::ScriptManager(Engine* EngineSource, Allocator* AllocatorSource) :
	engine(EngineSource),
	allocator(AllocatorSource)
{
}

Script* ScriptManager::GetScript(const std::string& Name)
{
	Script* result = nullptr;

	if (Name == "Tester")
	{
		result = new (NewScript()) Tester(engine);
	}

	return result;
}

Script* ScriptManager::NewScript()
{
	Script * object = (Script*)allocator->Alloc(sizeof(Script));

	return object;
}
