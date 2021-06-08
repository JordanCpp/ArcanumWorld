#include "Platform.h"
#include <iostream>
#include "Graphics/Image.h"
#include "Game/Engine.h"
#include "Common/XmlWriter.hpp"
#include "Managers/ObjectManager.h"
#include "Managers/XmlManager.h"

void CreateLocation(size_t size)
{
    size_t max_tiles = size * size;

    XmlWriter f("Files\\Locations\\test.xml");

    f.OpenTag("Location");

    f.OpenTag("Info");
    f.Node("Size", std::to_string(size));
    f.CloseTag("Info");

    f.OpenTag("Tiles");
    f.OpenTag("Floor");

    for (size_t i = 0; i < max_tiles; i++)
    {
        f.OpenTag("Tile");
        f.Node("Proto", "default.xml");
        f.CloseTag("Tile");
    }

    f.CloseTag("Floor");
    f.CloseTag("Tiles");
    f.CloseTag("Location");
}

void EngineInit()
{
    LinearAllocator allocator(LinearAllocator::Mb * 4);

    Settings settings("Config.xml");
    Canvas screen(settings.WindowSize(), settings.Fps());
    XmlManager xml_manager(settings.Path());
    ResourceManager manager(&screen, settings.Path());
    ObjectManager objects(&manager, &xml_manager, &allocator);

    Engine engine(&settings, &screen, &manager, &objects, &xml_manager);
    engine.Run();
}

int main(int argc, char**argv)
{
    std::cout << argc << '\n';
    std::cout << argv[0] << '\n';

    //CreateLocation(100);
    EngineInit();

    //TestCode();

    return 0;
}
