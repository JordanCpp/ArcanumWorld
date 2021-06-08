#ifndef SCRIPT_H
#define SCRIPT_H

#include "Engine.h"

class Script
{
public:
    Script(Engine * EngineSource);
    ~Script();
    Engine * GetEngine();

    void MapEnter();
    void MapExit();
    void MapUpdate();
private:
    Engine * engine;
};

#endif // SCRIPT_H