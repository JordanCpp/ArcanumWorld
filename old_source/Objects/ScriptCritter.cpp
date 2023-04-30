#include "ScriptCritter.h"

ScriptCritter::ScriptCritter(Engine* EngineSource):
	Script(EngineSource)
{
}

void ScriptCritter::Init(Critter* CritterSource)
{
	critter = CritterSource;
}

Critter* ScriptCritter::Self()
{
	return critter;
}