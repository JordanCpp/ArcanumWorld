#ifndef Arcanum_Objects_Scenery_hpp
#define Arcanum_Objects_Scenery_hpp

#include <Arcanum/Graphics/Sprite.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Scenery
		{
		public:
			Scenery();
			void Init(Graphics::Sprite* sprite);
			Graphics::Sprite* Body();
			const LDL::Graphics::Point2u& Pos();
		private:
			LDL::Graphics::Point2u _Pos;
			Graphics::Sprite* _Body;
		};
	}
}

#endif