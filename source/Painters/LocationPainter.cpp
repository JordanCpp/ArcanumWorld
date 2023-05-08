#include <Arcanum/Painters/LocationPainter.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Painters;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

LocationPainter::LocationPainter(Render* render) :
	_Render(render)
{
}

void LocationPainter::DrawTiles(Location* location, const Point2u& start)
{
	Point2u pos;

	for (size_t i = 0; i < location->Tiles().size(); i++)
	{
		pos = location->Tiles()[i].Pos();

		Texture* texture = location->Tiles()[i].Body()->Single()->GetTexture();

		_Render->Draw(texture, Point2u(start.PosX() + pos.PosX(), start.PosY() + pos.PosY()));
	}
}

void LocationPainter::DrawSceneries(Location* location, const Point2u& start)
{
	Point2u tilePos;
	Point2u targetPos;

	for (size_t i = 0; i < location->Sceneries().size(); i++)
	{
		tilePos = location->Tiles()[i].Pos();

		Sprite* sprite = location->Sceneries()[i].Body();

		if (sprite != nullptr)
		{
			size_t h = sprite->Single()->GetTexture()->Size().PosY();

			_Render->Draw(sprite->Single()->GetTexture(), Point2u(start.PosX() + tilePos.PosX(), start.PosY() + tilePos.PosY() - h));
		}
	}
}

void LocationPainter::Draw(Location* location, const Point2u& start)
{
	DrawTiles(location, start);
	DrawSceneries(location, start);
}