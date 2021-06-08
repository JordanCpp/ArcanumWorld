#ifndef ENGINE_H
#define ENGINE_H

#include "Settings.h"
#include "../Graphics/Canvas.h"
#include "../Managers/ResourceManager.h"
#include "../Game/Location.h"
#include "../Game/State.h"
#include "../Managers/XmlManager.h"

class Engine
{
public:
    Engine(const std::string& Name);
    ~Engine();
    void Run();
    Canvas * GetCanvas();
    Settings * GetSettings();
    ResourceManager * GetManager();
    ObjectManager* GetObjects();
    XmlManager* GetXmlManager();
private:
    Settings settings;
    LinearAllocator allocator;
    Canvas canvas;
    State state;
    XmlManager xml_manager;
    ResourceManager manager;
    ObjectManager objects;
};

#endif // ENGINE_H
