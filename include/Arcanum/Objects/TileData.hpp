#ifndef Arcanum_Objects_TileData_hpp
#define Arcanum_Objects_TileData_hpp

#include <vector>
#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class TileData
		{
		public:
			void Reset(const LDL::Graphics::Point2u& size);
			const std::vector<float>& Vertexs();
			const std::vector<float>& Coords();
		private:
			std::vector<float> _Vertexs;
			std::vector<float> _Coords;
		};
	}
}

#endif