#include <Arcanum/Objects/Scenery.hpp>

using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

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