#include <Arcanum/Graphics/Image.hpp>

using namespace Arcanum::Graphics;
using namespace LDL::Graphics;

Image::Image(LDL::Graphics::RenderContext* renderContext, const Point2u& size, uint8_t* pixels, const Point2u& offset, const Point2u& delta) :
	_Texture(renderContext, size, pixels, 4),
	_Offset(offset),
	_Delta(delta)
{
}

Texture* Image::GetTexture()
{
	return &_Texture;
}