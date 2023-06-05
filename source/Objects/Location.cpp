#include <Arcanum/Objects/Location.hpp>

using namespace Arcanum::Objects;
using namespace LDL::Math;

Location::Location(LocationData* locationData, Managers::ObjectManager* objectManager, Painters::LocationPainter* locationPainter, Managers::SpriteManager* spriteManager) :
	_LocationData(locationData),
	_ObjectManager(objectManager),
	_LocationPainter(locationPainter),
	_SpriteManager(spriteManager)
{
}

void Location::Draw(const Vec2u& start)
{
	_LocationPainter->DrawTiles(start);
	_LocationPainter->DrawSceneries(start);
}

Scenery* Location::NewScenery(const Vec2u& pos, const std::string& path)
{
	Scenery * result = _ObjectManager->NewScenery(path);

	result->Pos(pos);

	_LocationData->Append(result);

	return result;
}

Tile* Location::NewTile(const LDL::Math::Vec2u& pos, const std::string& path)
{
	size_t index = _LocationData->Index(pos);

	Tile* result = &_LocationData->TileObjects()[index];

	result->Init(_SpriteManager->GetTile(path));

	return result;
}