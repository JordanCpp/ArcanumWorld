#include <Arcanum/Text/Font.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;
using namespace Arcanum::Text;

Font::Font(Rasterizer* rasterizer, Readers::MemoryReader& reader, size_t fontSize) :
	_Rasterizer(rasterizer)
{
	_Data = reader.Content();

	FT_Error error = FT_New_Memory_Face(rasterizer->Get(), _Data.data(), _Data.size(), 0, &_Face);

	if (error != 0)
		throw RuntimeError("FT_Init_FreeType failed: ");

	error = FT_Set_Pixel_Sizes(_Face, 0, fontSize);

	if (error != 0)
		throw RuntimeError("FT_Set_Pixel_Sizes failed: ");
}

Font::~Font()
{
	FT_Done_Face(_Face);
}

FT_Face Font::Get()
{
	return _Face;
}