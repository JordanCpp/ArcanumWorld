#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <LDL/Graphics/Isometric.hpp>
#include <Arcanum/Objects/Critter.hpp>
#include <Arcanum/Objects/Scenery.hpp>
#include <Arcanum/Objects/Tile.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			void Reset(const LDL::Math::Vec2u& size);
			void CalculateTiles();
			size_t Index(size_t x, size_t y);
			size_t Index(const LDL::Math::Vec2u& pos);
			const LDL::Math::Vec2u& Size();
			std::vector<Tile>& TileObjects();
			std::vector<Scenery*>& SceneryObjects();
			Scenery* GetScenery(size_t x, size_t y);
		private:
			LDL::Graphics::Isometric _Isometric;
			LDL::Math::Vec2u         _Size;

			std::vector<Tile>     _TileObjects;
			std::vector<Scenery*> _SceneryObjects;

			std::vector<Scenery*> _SceneryTiles;
		};
	}
}

#endif