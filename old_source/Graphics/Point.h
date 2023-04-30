#ifndef POINT_H
#define POINT_H

#include <cstdint>
#include "Point.h"

class Point
{
public:
    Point(size_t x, size_t y);
    ~Point();
    size_t PosX();
    size_t PosY();
    void PosX(size_t x);
    void PosY(size_t y);
private:
    size_t pos_x;
    size_t pos_y;
};

#endif // POINT_H
