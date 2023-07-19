#include <Arcanum/Text/GlyphRender.hpp>
#include <Arcanum/Core/RuntimeError.hpp>
#include <cassert>

using namespace LDL::Math;
using namespace LDL::Graphics;
using namespace Arcanum::Core;
using namespace Arcanum::Text;

GlyphRender::GlyphRender() :
	_Surface(Vec2u(256, 256), Vec2u(256, 256), 4)
{
}

bool GlyphRender::Render(Font* font, size_t symbol)
{
	FT_Face face = font->Get();

	assert(face != nullptr);

	FT_UInt index = FT_Get_Char_Index(face, symbol);

	if (!index)
		throw RuntimeError("FT_Get_Char_Index failed");

	FT_Error error = FT_Load_Glyph(face, index, FT_LOAD_DEFAULT);

	if (error != 0)
		throw RuntimeError("FT_Load_Glyph failed");

	error = FT_Render_Glyph(face->glyph, FT_Render_Mode::FT_RENDER_MODE_NORMAL);

	if (error != 0)
		throw RuntimeError("FT_Render_Glyph failed");

	FT_Bitmap bitmap = face->glyph->bitmap;

	_Surface.Resize(Vec2u(bitmap.width, bitmap.rows));

	uint8_t* pixels = _Surface.Pixels();

	for (size_t y = 0; y < bitmap.rows; y++)
	{
		for (size_t x = 0; x < bitmap.width; x++)
		{
			size_t k = y * bitmap.pitch + x;

			pixels[k * 4 + 0] = 255;
			pixels[k * 4 + 1] = 255;
			pixels[k * 4 + 2] = 255;
			pixels[k * 4 + 3] = bitmap.buffer[k];
		}
	}

	return true;
}

Surface* GlyphRender::Result()
{
	return &_Surface;
}