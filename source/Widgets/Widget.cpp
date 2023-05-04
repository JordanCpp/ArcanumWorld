#include <Arcanum/Widgets/Widget.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;

Widget::Widget(LDL::Graphics::Render* render, const Point2u& pos, const Point2u& size) :
	_Render(render),
	_Area(pos, size)
{
}

Widget::~Widget()
{
}

const Point2u Widget::Pos()
{
	return _Area.Pos();
}

const Point2u Widget::Size()
{
	return _Area.Size();
}

LDL::Graphics::Render* Widget::Render()
{
	return _Render;
}