#ifndef RECT_H
#define RECT_H

#include <cstdint>
#include "Point.h"

class Rect
{
public:
  Rect(size_t x, size_t y, size_t w, size_t h);
  bool Contains(Point Pt);
  size_t PosX();
  size_t PosY();
  size_t Width();
  size_t Height();

private:
    size_t pos_x;
    size_t pos_y;
    size_t width;
    size_t height;
};

#endif // RECT_H
