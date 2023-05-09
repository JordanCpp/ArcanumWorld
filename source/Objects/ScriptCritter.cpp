#include <Arcanum/Objects/ScriptCritter.hpp>
#include <stdio.h>

using namespace Arcanum::Objects;

Critter* ScriptCritter::Self()
{
	return _Critter;
}

void ScriptCritter::Init(Critter* critter)
{
	_Critter = critter;
}