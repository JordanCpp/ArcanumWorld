#ifndef _TestCritter_h_
#define _TestCritter_h_ 

#include "../Objects/ScriptCritter.h"

class TestCritter: public ScriptCritter
{
public:
	TestCritter(Engine* EngineSource);
	void MapEnter();

private:
};

#endif