#include <Arcanum/Objects/Location.hpp>

using namespace Arcanum::Objects;
using namespace LDL::Graphics;

size_t Location::Index(size_t x, size_t y)
{
    return (_Size.PosX() * y) + x;
}

const Point2u& Location::Size()
{
    return _Size;
}

void Location::Size(const Point2u& size)
{
    _Size = size;

    _Tiles.resize(_Size.PosX() * _Size.PosY());
    _Sceneries.resize(_Size.PosX() * _Size.PosY());
}

std::vector<Tile>& Location::Tiles()
{
    return _Tiles;
}

std::vector<Scenery>& Location::Sceneries()
{
    return _Sceneries;
}