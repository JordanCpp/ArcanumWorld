#include <Arcanum/Widgets/Widget.hpp>

using namespace Arcanum::Widgets;
using namespace LDL::Graphics;

Widget::Widget(Render* render, const Point2u& pos, const Point2u& size) :
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

Render* Widget::GetRender()
{
	return _Render;
}