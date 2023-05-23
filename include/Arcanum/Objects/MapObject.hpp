#ifndef Arcanum_Objects_MapObject_hpp
#define Arcanum_Objects_MapObject_hpp

#include <LDL/Graphics/Primitives/Point2u.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class MapObject
		{
		public:
			const LDL::Graphics::Point2u& Pos();
			void Pos(const LDL::Graphics::Point2u& pos);
		private:
			LDL::Graphics::Point2u _Pos;

		};
	}
}

#endif