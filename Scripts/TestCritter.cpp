#include "TestCritter.h"

TestCritter::TestCritter(Engine* EngineSource) :
	ScriptCritter(EngineSource)
{
}

void TestCritter::MapEnter()
{
	if (Self()->Stat(Stats::Strength) > 5)
	{

	}
}