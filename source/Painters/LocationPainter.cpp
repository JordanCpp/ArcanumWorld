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

	for (size_t i = 0; i < _Location->TileObjects().size(); i++)
	{
		pos = _Location->TileObjects()[i].Pos();

		Texture* texture = _Location->TileObjects()[i].Body()->Single()->GetTexture();

		_Render->Draw(texture, Point2u(start.PosX() + pos.PosX(), start.PosY() + pos.PosY()));
	}
}

void LocationPainter::DrawSceneries(const Point2u& start)
{
	for (size_t i = 0; i < _Location->SceneryObjects().size(); i++)
	{
		Scenery* object  = _Location->SceneryObjects()[i];
		size_t   index   = _Location->Index(object->Pos());
		Point2u  tilePos = _Location->TileObjects()[index].Pos();

		Sprite* sprite = object->Body();

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