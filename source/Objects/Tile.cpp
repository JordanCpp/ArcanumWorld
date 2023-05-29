#include <Arcanum/Objects/Tile.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;
using namespace LDL::Math;

Tile::Tile() :
	_Body(nullptr)
{
}

const Vec2u& Tile::Pos()
{
	return _Pos;
}

void Tile::Pos(const Vec2u& pos)
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