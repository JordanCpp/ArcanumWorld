#include <Arcanum/Text/Rasterizer.hpp>
#include <Arcanum/Core/RuntimeError.hpp>

using namespace Arcanum::Core;
using namespace Arcanum::Text;

Rasterizer::Rasterizer()
{
	FT_Error error = FT_Init_FreeType(&_Library);

	if (error != 0)
		throw RuntimeError("FT_Init_FreeType failed");
}

Rasterizer::~Rasterizer()
{
	FT_Done_FreeType(_Library);
}

FT_Library Rasterizer::Get()
{
	return _Library;
}