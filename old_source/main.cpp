#include "Managers/SpriteManager.h"
#include "Managers/XmlManager.h"
#include "Managers/ObjectManager.h"
#include "Managers/ScriptManager.h"
#include "Game/Engine.h"
#include "Game/Settings.h"
#include "Graphics/Canvas.h"
#include "Allocators/LinearAllocator.h"

int main(int argc, char** argv)
{
    std::cout << argc << '\n';
    std::cout << argv[0] << '\n';

    Engine engine;

    Settings settings("Config.xml");
    LinearAllocator allocator(LinearAllocator::Mb * 4);
    Canvas screen(settings.WindowSize(), settings.Fps());
    SpriteManager sprite_manager;
    XmlManager xml_manager(settings.Path());
    ScriptManager script_manager(&engine, &allocator);
    ImageManager image_manager(&screen, settings.Path());
    ObjectManager object_manager(&xml_manager, &allocator, &script_manager, &image_manager);
    Location location(&object_manager);

    engine.Init(&screen, &sprite_manager, &xml_manager, &object_manager, &script_manager, &location, &settings, &image_manager);
    engine.Run();

    return 0;
}