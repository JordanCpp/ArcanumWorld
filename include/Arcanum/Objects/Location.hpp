#ifndef Arcanum_Objects_Location_hpp
#define Arcanum_Objects_Location_hpp

#include <Arcanum/Objects/Tile.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Location
		{
		public:
			size_t Index(size_t x, size_t y);
			const LDL::Graphics::Point2u& Size();
			void Size(const LDL::Graphics::Point2u& size);
			std::vector<Tile>& Tiles();
		private:
			LDL::Graphics::Point2u _Size;
			std::vector<Tile> _Tiles;
		};
	}
}

#endif