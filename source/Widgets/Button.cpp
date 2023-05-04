#include <Arcanum/Widgets/Button.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;

Button::Button(LDL::Graphics::Render* render, const Point2u& pos, const Point2u& size) :
	Widget(render, pos, size)
{
}

void Button::Draw()
{
	Render()->Color(Color(192, 192, 192));
	Render()->Fill(Pos(), Size());
}