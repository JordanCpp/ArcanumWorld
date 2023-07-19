#ifndef Arcanum_Text_Rasterizer_hpp
#define Arcanum_Text_Rasterizer_hpp

#include <ft2build.h>
#include FT_FREETYPE_H

namespace Arcanum
{
	namespace Text
	{
		class Rasterizer
		{
		public:
			Rasterizer();
			~Rasterizer();
			FT_Library Get();
		private:
			FT_Library _Library;
		};
	}
}

#endif    