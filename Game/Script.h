#ifndef SCRIPT_H
#define SCRIPT_H

#include "Engine.h"

class Script
{
public:
    Script(Engine * EngineSource);
    ~Script();
    Engine * GetEngine();

    virtual void MapEnter() = 0;
    virtual void MapExit() = 0;
    virtual void MapUpdate() = 0;
private:
    Engine * engine;
};

#endif // SCRIPT_H