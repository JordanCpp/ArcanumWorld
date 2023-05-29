#include <Arcanum/Widgets/Button.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;
using namespace LDL::Math;

Button::Button(Render* render, const Vec2u& pos, const Vec2u& size) :
	Widget(render, pos, size)
{
}

void Button::Draw()
{
	GetRender()->Color(Color(192, 192, 192));
	GetRender()->Fill(Pos(), Size());
}