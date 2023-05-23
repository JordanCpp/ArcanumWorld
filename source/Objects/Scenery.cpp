#include <Arcanum/Objects/Scenery.hpp>

using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;
using namespace LDL::Graphics;

Scenery::Scenery() :
	_Body(nullptr)
{
}

void Scenery::Init(Sprite* sprite)
{
	_Body = sprite;
}

Sprite* Scenery::Body()
{
	return _Body;
}

const Point2u& Scenery::Pos()
{
	return _MapObject.Pos();
}

void Scenery::Pos(const Point2u& pos)
{
	_MapObject.Pos(pos);
}