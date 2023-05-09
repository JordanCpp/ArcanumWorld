#include <Arcanum/Painters/LocationPainter.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Painters;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

LocationPainter::LocationPainter(Render* render, Location* location) :
	_Render(render),
	_Location(location)
{
}

void LocationPainter::DrawTiles(const Point2u& start)
{
	Point2u pos;

	for (size_t i = 0; i < _Location->Tiles().size(); i++)
	{
		pos = _Location->Tiles()[i].Pos();

		Texture* texture = _Location->Tiles()[i].Body()->Single()->GetTexture();

		_Render->Draw(texture, Point2u(start.PosX() + pos.PosX(), start.PosY() + pos.PosY()));
	}
}

void LocationPainter::DrawSceneries(const Point2u& start)
{
	Point2u tilePos;
	Point2u targetPos;

	for (size_t i = 0; i < _Location->Sceneries().size(); i++)
	{
		tilePos = _Location->Tiles()[i].Pos();

		Sprite* sprite = _Location->Sceneries()[i].Body();

		if (sprite != nullptr)
		{
			size_t h = sprite->Single()->GetTexture()->Size().PosY();

			_Render->Draw(sprite->Single()->GetTexture(), Point2u(start.PosX() + tilePos.PosX(), start.PosY() + tilePos.PosY() - h));
		}
	}
}

void LocationPainter::Draw(const Point2u& start)
{
	DrawTiles(start);
	DrawSceneries(start);
}