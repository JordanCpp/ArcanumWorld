#include "Script.h"

Script::Script(Engine * EngineSource):
    engine(EngineSource)
{
}

Script::~Script()
{
    engine = nullptr;
}

Engine * Script::GetEngine()
{
    return engine;
}

void Script::MapEnter()
{
}

void Script::MapExit()
{
}

void Script::MapUpdate()
{
}