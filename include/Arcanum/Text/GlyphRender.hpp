#ifndef Arcanum_Text_GlyphRender_hpp
#define Arcanum_Text_GlyphRender_hpp

#include <Arcanum/Text/Font.hpp>
#include <LDL/Graphics/Surface.hpp>

namespace Arcanum
{
	namespace Text
	{
		class GlyphRender
		{
		public:
			GlyphRender();
			bool Render(Font* font, size_t symbol);
			LDL::Graphics::Surface* Result();
		private:
			LDL::Graphics::Surface _Surface;
		};
	}
}

#endif    