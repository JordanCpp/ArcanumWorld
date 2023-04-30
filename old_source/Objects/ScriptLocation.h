#ifndef _Objects_ScriptLocation_h_
#define _Objects_ScriptLocation_h_ 

#include "Location.h"
#include "Script.h"

class Location;

class ScriptLocation : public Script
{
public:
	ScriptLocation(Engine* EngineSource);
	void Init(Location* LocationSource);
private:
	Location* location;
};

#endif