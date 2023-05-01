#include <Arcanum/Objects/Tile.hpp>

using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

Tile::Tile() :
	_Body(nullptr)
{
}

void Tile::Init(Sprite* sprite)
{
	_Body = sprite;
}