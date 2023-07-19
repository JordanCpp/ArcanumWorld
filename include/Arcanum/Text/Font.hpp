#ifndef Arcanum_Text_Font_hpp
#define Arcanum_Text_Font_hpp

#include <Arcanum/Text/Rasterizer.hpp>
#include <Arcanum/Readers/MemoryReader.hpp>
#include <string>

namespace Arcanum
{
	namespace Text
	{
		class Font
		{
		public:
			Font(Rasterizer* rasterizer, Readers::MemoryReader & reader, size_t fontSize);
			~Font();
			FT_Face Get();
		private:
			Rasterizer* _Rasterizer;
			FT_Face _Face;
			std::vector<uint8_t> _Data;
		};
	}
}

#endif    