#include "Engine.h"
#include "../GUI/GUI_Window.h"
#include "../GUI/GUI_Button.h"

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

    size_t pos_x = 0;
    size_t pos_y = 0;

    GUI::Window main_window(canvas, Rect(0, 0, 800, 600));
    GUI::Button btn1(canvas, Rect(0, 5, 150, 35));
    main_window.Attach(&btn1);

    GUI::Button btn2(canvas, Rect(0, 45, 150, 35));
    main_window.Attach(&btn2);

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

        if (report.type == SDL_MOUSEMOTION)
        {
            pos_x = report.motion.x;
            pos_y = report.motion.y;
        }

        location->DrawTiles(Point(x, y));

        main_window.Run(Point(pos_x, pos_y));
    }
}