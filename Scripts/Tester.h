#ifndef _Scripts_Tester_h
#define _Scripts_Tester_h

#include "../Game/Script.h"

class Tester: public Script
{
public:
    Tester(Engine* EngineSource);
    void MapEnter();
    void MapExit();
    void MapUpdate();
private:

};

#endif