#include "Color.h"

Color::Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a):
    red(r),
    green(g),
    blue(b),
    alpha(a)
{
}

Color::~Color()
{
}

uint8_t Color::Red()
{
    return red;
}

uint8_t Color::Green()
{
    return green;
}

uint8_t Color::Blue()
{
    return blue;
}

uint8_t Color::Alpha()
{
    return alpha;
}
