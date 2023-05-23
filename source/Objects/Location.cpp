#include <Arcanum/Objects/Location.hpp>
#include <Arcanum/Objects/LocationLimits.hpp>

using namespace Arcanum::Objects;
using namespace LDL::Graphics;

void Location::Reset(const Point2u& size)
{
    _Size = size;

	size_t sz = _Size.PosX() * _Size.PosY();

    _TileObjects.resize(sz);
	_SceneryTiles.resize(sz);

    _SceneryObjects.reserve(LocationLimits::Sceneries);

	CalculateTiles();
}

void Location::CalculateTiles()
{
	for (size_t x = 0; x < Size().PosX(); x++)
	{
		for (size_t y = 0; y < Size().PosY(); y++)
		{
			size_t dx = y * Tile::Width / 2;
			size_t dy = x * Tile::Height;

			Point2u pt = _Isometric.CartesianToIsometric(Point2u(dx, dy));

			size_t index = Index(x, y);
			
			TileObjects()[index].Pos(pt);
		}
	}
}

size_t Location::Index(size_t x, size_t y)
{
    return (_Size.PosX() * y) + x;
}

size_t Location::Index(const Point2u& pos)
{
	return Index(pos.PosX(), pos.PosY());
}

const Point2u& Location::Size()
{
    return _Size;
}

std::vector<Tile>& Location::TileObjects()
{
    return _TileObjects;
}

std::vector<Scenery*>& Location::SceneryObjects()
{
    return _SceneryObjects;
}

Scenery* Location::GetScenery(size_t x, size_t y)
{
	return _SceneryObjects[Index(x, y)];
}