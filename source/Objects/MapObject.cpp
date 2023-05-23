#include <Arcanum/Objects/MapObject.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Objects;

const Point2u& MapObject::Pos()
{
	return _Pos;
}

void MapObject::Pos(const Point2u& pos)
{
	_Pos = pos;
}