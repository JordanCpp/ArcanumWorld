#include "Rect.h"

Rect::Rect(size_t x, size_t y, size_t w, size_t h):
    pos_x(x),
    pos_y(y),
    width(w),
    height(h)
{
}

bool Rect::Contains(Point Pt)
{
  return Pt.PosX() >= pos_x && Pt.PosY()  >= pos_y && Pt.PosX() <= pos_x + width && Pt.PosY() <= pos_y + height;
}

size_t Rect::PosX()
{
  return pos_x;
}

size_t Rect::PosY()
{
  return pos_y;
}

size_t Rect::Width()
{
  return width;
}

size_t Rect::Height()
{
  return height;
}
