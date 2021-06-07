#ifndef COLOR_H
#define COLOR_H

#include <cstdint>

class Color
{
public:
    Color(uint8_t r, uint8_t g, uint8_t b, uint8_t a = 255);
    ~Color();
    uint8_t Red();
    uint8_t Green();
    uint8_t Blue();
    uint8_t Alpha();
private:
    uint8_t red;
    uint8_t green;
    uint8_t blue;
    uint8_t alpha;
};

#endif // COLOR_H
