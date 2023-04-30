#include "Point.h"

Point::Point(size_t x, size_t y):
pos_x(x),
pos_y(y)
{
}

Point::~Point()
{
}

size_t Point::PosX()
{
  return pos_x;
}

size_t Point::PosY()
{
  return pos_y;
}

void Point::PosX(size_t x)
{
    pos_x = x;
}

void Point::PosY(size_t y)
{
    pos_y = y;
}
