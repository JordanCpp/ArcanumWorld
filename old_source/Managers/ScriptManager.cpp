#include "ScriptManager.h"

ScriptManager::ScriptManager(Engine* EngineSource, Allocator* AllocatorSource):
	engine(EngineSource),
	allocator(AllocatorSource)
{
}

ScriptCritter* ScriptManager::NewCritter()
{
	return (ScriptCritter*)allocator->Alloc(sizeof(ScriptCritter));
}

ScriptLocation* ScriptManager::NewLocation()
{
	return (ScriptLocation*)allocator->Alloc(sizeof(ScriptLocation));
}

ScriptTile* ScriptManager::NewTile()
{
	return (ScriptTile*)allocator->Alloc(sizeof(ScriptTile));
}

ScriptCritter* ScriptManager::GetCritter(const std::string& Name)
{
	ScriptCritter* result = nullptr;

	if (Name == "TestCritter")
	{

	}

	return new(NewCritter()) ScriptCritter(engine);
}

ScriptLocation* ScriptManager::GetLocation()
{
	return new(NewLocation()) ScriptLocation(engine);
}

ScriptTile* ScriptManager::GetTile()
{
	return new(NewTile()) ScriptTile(engine);
}