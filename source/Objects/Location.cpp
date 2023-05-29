#include <Arcanum/Objects/Location.hpp>
#include <Arcanum/Objects/LocationLimits.hpp>

using namespace Arcanum::Objects;
using namespace LDL::Graphics;
using namespace LDL::Math;

void Location::Reset(const Vec2u& size)
{
    _Size = size;

	size_t sz = _Size.x * _Size.y;

    _TileObjects.resize(sz);
	_SceneryTiles.resize(sz);

    _SceneryObjects.reserve(LocationLimits::Sceneries);

	CalculateTiles();
}

void Location::CalculateTiles()
{
	for (size_t x = 0; x < Size().x; x++)
	{
		for (size_t y = 0; y < Size().y; y++)
		{
			size_t dx = y * Tile::Width / 2;
			size_t dy = x * Tile::Height;

			Vec2u pt = _Isometric.CartesianToIsometric(Vec2u(dx, dy));

			size_t index = Index(x, y);
			
			TileObjects()[index].Pos(pt);
		}
	}
}

size_t Location::Index(size_t x, size_t y)
{
    return (_Size.x * y) + x;
}

size_t Location::Index(const Vec2u& pos)
{
	return Index(pos.x, pos.y);
}

const Vec2u& Location::Size()
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