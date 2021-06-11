#include "ScriptLocation.h"

ScriptLocation::ScriptLocation(Engine* EngineSource):
	Script(EngineSource)
{
}

void ScriptLocation::Init(Location* LocationSource)
{
	location = LocationSource;
}