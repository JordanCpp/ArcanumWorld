#include "Engine.h"
#include "../UI/MainMenu.h"

void Engine::Init(Canvas* CanvasSource, SpriteManager* SpriteSource, XmlManager* XmlSource, ObjectManager* ObjectSource, ScriptManager* ScriptSource, Location* LocationSource, Settings* SettingsSource, ImageManager* ImageSource)
{
    canvas = CanvasSource;
	sprite_manager = SpriteSource;
	xml_manager = XmlSource;
	object_manager = ObjectSource;
	script_manager = ScriptSource;
	location = LocationSource;
    setttings = SettingsSource;
    image_manager = ImageSource;

    location->Load(xml_manager->GetLocation("test.xml"));
}

void Engine::Run()
{
    SDL_Event report;

    size_t x = 0;
    size_t y = 0;
    size_t speed = Tile::Width;

    MainMenu main_menu(canvas, setttings, image_manager);

    while (canvas->GetEvent(report))
    {
        if (report.type == SDL_KEYDOWN)
        {
            if (report.key.keysym.sym == SDLK_d)
            {
                x = x - speed;
            }

            if (report.key.keysym.sym == SDLK_a)
            {
                x = x + speed;
            }

            if (report.key.keysym.sym == SDLK_w)
            {
                y = y + speed;
            }

            if (report.key.keysym.sym == SDLK_s)
            {
                y = y - speed;
            }
        }

        location->DrawTiles(Point(x, y));
    }
}