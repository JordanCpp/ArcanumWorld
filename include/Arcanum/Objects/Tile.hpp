#ifndef Arcanum_Objects_Tile_hpp
#define Arcanum_Objects_Tile_hpp

#include <Arcanum/Graphics/Sprite.hpp>

namespace Arcanum
{
	namespace Objects
	{
		class Tile
		{
		public:
			enum
			{
				Width  = 78,
				Height = 40
			};

			Tile();
			void Init(Graphics::Sprite* sprite);
		private:
			Graphics::Sprite* _Body;
		};
	}
}

#endif