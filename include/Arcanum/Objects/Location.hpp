#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/LocationData.hpp>
#include <Arcanum/Managers/ObjectManager.hpp>
#include <Arcanum/Painters/LocationPainter.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			Location(LocationData* locationData, Managers::ObjectManager* objectManager, Painters::LocationPainter* locationPainter, Managers::SpriteManager * spriteManager);
			void Draw(const LDL::Math::Vec2u& start);
			Scenery* NewScenery(const LDL::Math::Vec2u& pos, const std::string& path);
			Tile* NewTile(const LDL::Math::Vec2u& pos, const std::string& path);
		private:
			LocationData* _LocationData;
			Managers::ObjectManager* _ObjectManager;
			Painters::LocationPainter* _LocationPainter;
			Managers::SpriteManager* _SpriteManager;
		};
	}
}

#endif