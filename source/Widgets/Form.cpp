#include <Arcanum/Widgets/Form.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;

Form::Form(Render* render, const Point2u& pos, const Point2u& size) :
	Widget(render, pos, size)
{
}

void Form::Attach(Widget* widget)
{
	_Container.Append(widget);
}

void Form::Draw()
{
	_Container.Draw();
}