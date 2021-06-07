#include "Script.h"

Script::Script(Engine * EngineSource):
    engine(EngineSource)
{
}

Script::~Script()
{
}

Engine * Script::GetEngine()
{
    return engine;
}
