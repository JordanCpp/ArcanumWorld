#ifndef _Objects_ScriptCritter_h_
#define _Objects_ScriptCritter_h_ 

#include "Critter.h"
#include "Script.h"

class Critter;

class ScriptCritter: public Script
{
public:
	ScriptCritter(Engine* EngineSource);
	void Init(Critter* CritterSource);
	Critter* Self();
private:
	Critter* critter;
};

#endif