#include <Arcanum/Painters/LocationPainter.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Painters;
using namespace Arcanum::Objects;
using namespace Arcanum::Graphics;

LocationPainter::LocationPainter(Render* render) :
	_Render(render)
{
}

void LocationPainter::Draw(Location* location, LDL::Graphics::Point2u& start)
{
	for (size_t x = 0; x < location->Size().PosX(); x++)
	{
		for (size_t y = 0; y < location->Size().PosY(); y++)
		{
			size_t dx = y * Tile::Width / 2;
			size_t dy = x * Tile::Height;
			 
			Point2u pt = _Isometric.CartesianToIsometric(Point2u(dx, dy));

			size_t   index   = location->Index(x, y);
			Texture* texture = location->Tiles()[index].Body()->GetImage(0)->GetTexture();

			_Render->Draw(texture, Point2u(start.PosX() + pt.PosX(), start.PosY() + pt.PosY()));
		}
	}

	for (size_t x = 0; x < location->Size().PosX(); x++)
	{
		for (size_t y = 0; y < location->Size().PosY(); y++)
		{
			size_t dx = y * Tile::Width / 2;
			size_t dy = x * Tile::Height;

			Point2u pt = _Isometric.CartesianToIsometric(Point2u(dx, dy));

			size_t   index = location->Index(x, y);
			Sprite* sprite = location->Sceneries()[index].Body();



			if (sprite != nullptr)
			{
				size_t w = 0;
				size_t h = sprite->GetImage(0)->GetTexture()->Size().PosY();

				_Render->Draw(sprite->GetImage(0)->GetTexture(), Point2u(start.PosX() + pt.PosX(), start.PosY() + pt.PosY() - h));
			}
		}
	}
}