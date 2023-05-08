#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/Tile.hpp>
#include <Arcanum/Objects/Scenery.hpp>
#include <LDL/Graphics/Isometric.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			void Reset(const LDL::Graphics::Point2u& size);
			void CalculateTiles();
			size_t Index(size_t x, size_t y);
			const LDL::Graphics::Point2u& Size();
			std::vector<Tile>& Tiles();
			std::vector<Scenery>& Sceneries();
		private:
			LDL::Graphics::Isometric _Isometric;
			LDL::Graphics::Point2u _Size;
			std::vector<Tile> _Tiles;
			std::vector<Scenery> _Sceneries;
		};
	}
}

#endif