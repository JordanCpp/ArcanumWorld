#ifndef CANVAS_H
#define CANVAS_H

#include <SDL2/SDL.h>
#include "Point.h"
#include "Rect.h"
#include "Color.h"

class Canvas
{
public:
    Canvas(Point Size, size_t Fps);
    ~Canvas();
    bool GetEvent(SDL_Event & Dest);
    SDL_Renderer * Render();
    void FillRect(Rect Rt, Color Cr);
    void DrawRect(Rect Rt, Color Cr);
private:
    bool           running;
    SDL_Renderer * render;
    SDL_Window   * window;
    size_t         fps;
    Point          size;
};

#endif // CANVAS_H
