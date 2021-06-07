#ifndef IMAGE_H
#define IMAGE_H

#include "Canvas.h"
#include <string>

class Image
{
public:
    Image(Canvas * Source, const std::string & Name);
    ~Image();
    void Draw(Point Pt);
    void Draw(Point Pt, Point Sz);
    int Width();
    int Height();
private:
    SDL_Surface * surface;
    SDL_Texture * texture;
    Canvas      * canvas;
    int        width;
    int        height;
};

#endif // IMAGE_H
