#include "Canvas.h"
#include <iostream>

Canvas::Canvas(Point Size, size_t Fps):
    running(true),
    fps(Fps),
    size(Size)
{
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cout << "SDL_Init: " << SDL_GetError() << std::endl;
    }

    window = SDL_CreateWindow("Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, size.PosX(), size.PosY(), 0);

    if (window == NULL)
    {
        std::cout << "SDL_CreateWindow: " << SDL_GetError() << std::endl;
    }

    render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if (render == NULL)
    {
        std::cout << "SDL_CreateRenderer: " << SDL_GetError() << std::endl;
    }
}

Canvas::~Canvas()
{
    SDL_DestroyRenderer(render);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

bool Canvas::GetEvent(SDL_Event & Dest)
{
    SDL_Event event;

    if (running == true)
    {
        SDL_RenderPresent(render);
        SDL_SetRenderDrawColor(render, 240, 240, 240, 0);
        SDL_RenderClear(render);

        size_t start  = SDL_GetTicks();

        SDL_PollEvent(&event);

        Dest = event;

        if (event.type == SDL_QUIT)
        {
            running = false;
        }

        if (1000 / fps > SDL_GetTicks() - start)
        {
            SDL_Delay(1000 / fps - (SDL_GetTicks() - start));
        }
    }

    return running;
}

SDL_Renderer * Canvas::Render()
{
    return render;
}

void Canvas::FillRect(Rect Rt, Color Cr)
{
  SDL_Rect Rectangle;

  Rectangle.x = Rt.PosX();
  Rectangle.y = Rt.PosY();
  Rectangle.w = Rt.Width();
  Rectangle.h = Rt.Height();

  SDL_SetRenderDrawColor(render, Cr.Red(), Cr.Green(), Cr.Blue(), Cr.Alpha());
  SDL_RenderFillRect(render, &Rectangle);
}

void Canvas::DrawRect(Rect Rt, Color Cr)
{
  SDL_Rect Rectangle;

  Rectangle.x = Rt.PosX();
  Rectangle.y = Rt.PosY();
  Rectangle.w = Rt.Width();
  Rectangle.h = Rt.Height();

  SDL_SetRenderDrawColor(render, Cr.Red(), Cr.Green(), Cr.Blue(), Cr.Alpha());
  SDL_RenderDrawRect(render, &Rectangle);
}
