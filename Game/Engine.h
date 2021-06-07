#ifndef ENGINE_H
#define ENGINE_H

#include "Settings.h"
#include "../Graphics/Canvas.h"
#include "ResourceManager.h"
#include "../Game/Location.h"
#include "../Game/State.h"

class Engine
{
public:
    Engine(Settings * SourceSettings, Canvas * CanvasSource, ResourceManager * ManagerSource);
    ~Engine();
    void Run();
    Canvas * GetCanvas();
    Settings * GetSettings();
    ResourceManager * GetManager();
private:
    Settings * setting;
    Canvas * canvas;
    ResourceManager * manager;
    State state;
    XmlReader reader;
};

#endif // ENGINE_H
