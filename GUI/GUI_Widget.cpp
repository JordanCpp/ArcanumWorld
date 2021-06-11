#include "GUI_Widget.h"

using namespace GUI;

Widget::Widget(Canvas* CanvasSource, Rect rt):
	canvas(CanvasSource),
	area(rt),
	state(Widget::Normal)
{
}

void Widget::Attach(Widget* widget)
{
	widget->parent = this;
	widgets.push_back(widget);
}

size_t Widget::GetState()
{
	return state;
}

void Widget::State(size_t Value)
{
	state = Value;
}

Rect Widget::GetSize()
{
	return area;
}

Canvas* Widget::GetCanvas()
{
	return canvas;
}