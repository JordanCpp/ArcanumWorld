#ifndef _Objects_Script_h_
#define _Objects_Script_h_ 

class Engine;

class Script
{
public:
	Script(Engine * EngineSource);
	void MapEnter();
	void MapExit();
	void MapUpdate();
private:
	Engine* engine;
};

#endif