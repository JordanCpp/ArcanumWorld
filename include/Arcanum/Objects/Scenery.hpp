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
		private:
			Graphics::Sprite* _Body;
		};
	}
}

#endif