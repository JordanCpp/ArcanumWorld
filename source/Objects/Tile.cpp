#include <Arcanum/Objects/Tile.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

Tile::Tile() :
	_Body(nullptr)
{
}

const Point2u& Tile::Pos()
{
	return _Pos;
}

void Tile::Pos(const Point2u& pos)
{
	_Pos = pos;
}

void Tile::Init(Sprite* sprite)
{
	_Body = sprite;
}

Sprite* Tile::Body()
{
	return _Body;
}