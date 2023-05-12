#include <Arcanum/Widgets/Button.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;

Button::Button(Render* render, const Point2u& pos, const Point2u& size) :
	Widget(render, pos, size)
{
}

void Button::Draw()
{
	GetRender()->Color(Color(192, 192, 192));
	GetRender()->Fill(Pos(), Size());
}