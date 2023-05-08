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
			const LDL::Graphics::Point2u& Pos();
			void Pos(const LDL::Graphics::Point2u& pos);
			void Init(Graphics::Sprite* sprite);
			Graphics::Sprite* Body();
		private:
			LDL::Graphics::Point2u _Pos;
			Graphics::Sprite* _Body;
		};
	}
}

#endif