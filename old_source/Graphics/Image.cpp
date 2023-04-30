#include "Image.h"
#include <iostream>

Image::Image(Canvas * Source, const std::string & Name):
    canvas(Source)
{
    surface = SDL_LoadBMP(Name.c_str());

    if (surface == nullptr)
    {
        std::cout << "SDL_LoadBMP: " << Name << SDL_GetError() << std::endl;
        std::terminate();
    }

    SDL_SetColorKey(surface, SDL_TRUE, SDL_MapRGB(surface->format, 0, 0, 255));

    texture = SDL_CreateTextureFromSurface(canvas->Render(), surface);

    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);

    if (texture == nullptr)
    {
        std::cout << "SDL_CreateTextureFromSurface: " << SDL_GetError() << std::endl;
        std::terminate();
    }

    SDL_FreeSurface(surface);
}

Image::~Image()
{
  SDL_DestroyTexture(texture);
}

void Image::Draw(Point Pt)
{
  SDL_Rect rt;

  rt.x = Pt.PosX();
  rt.y = Pt.PosY();
  rt.w = Width();
  rt.h = Height();

  SDL_RenderCopy(canvas->Render(), texture, nullptr, &rt);
}

void Image::Draw(Point Pt, Point Sz)
{
  SDL_Rect rt;

  rt.x = Pt.PosX();
  rt.y = Pt.PosY();
  rt.w = Sz.PosX();
  rt.h = Sz.PosY();

  SDL_RenderCopy(canvas->Render(), texture, nullptr, &rt);
}

int Image::Width()
{
  return width;
}

int Image::Height()
{
  return height;
}
