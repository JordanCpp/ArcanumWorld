#ifndef ENGINE_H
#define ENGINE_H

#include "Settings.h"
#include "../Graphics/Canvas.h"
#include "../Managers/ResourceManager.h"
#include "../Game/Location.h"
#include "../Game/State.h"

class Engine
{
public:
    Engine(Settings * SourceSettings, Canvas * CanvasSource, ResourceManager * ManagerSource, ObjectManager* Objects);
    ~Engine();
    void Run();
    Canvas * GetCanvas();
    Settings * GetSettings();
    ResourceManager * GetManager();
    ObjectManager* GetObjects();
private:
    Settings * setting;
    Canvas * canvas;
    ResourceManager * manager;
    ObjectManager* objects;
    State state;
    XmlReader reader;
};

#endif // ENGINE_H
