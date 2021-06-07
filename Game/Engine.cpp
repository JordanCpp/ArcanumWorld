#include "Engine.h"
#include "../UI/MainMenu.h"

Engine::Engine(Settings * SourceSettings, Canvas * CanvasSource, ResourceManager * ManagerSource):
    setting(SourceSettings),
    canvas(CanvasSource),
    manager(ManagerSource),
    reader("", XmlReader::FromString)
{
}

Engine::~Engine()
{
}

void Engine::Run()
{
    SDL_Event report;

    Location location(GetManager(), "test.xml");

    size_t x      = GetSettings()->WindowSize().PosX() / 2;
    size_t y      = GetSettings()->WindowSize().PosY() / 2;
    size_t speed  = Tile::Width;

    MainMenu main_menu(GetCanvas(), GetSettings());

    while (GetCanvas()->GetEvent(report))
    {
        if (state.IsState() == State::MainMenu)
        {
            main_menu.Run();
        }
        else if (state.IsState() == State::Editor)
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

            location.DrawTiles(Point(x, y));
        }
    }
}

Canvas * Engine::GetCanvas()
{
    return canvas;
}

Settings * Engine::GetSettings()
{
    return setting;
}

ResourceManager * Engine::GetManager()
{
    return manager;
}
