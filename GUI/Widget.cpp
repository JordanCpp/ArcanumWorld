#include "Widget.h"

Widget::Widget(Canvas * CanvasSource, Rect Size):
    area(Size),
    state(Widget::Normal),
    canvas(CanvasSource),
    enabled(true),
    visible(true)
{
}

Widget::~Widget()
{
}

Canvas * Widget::GetCanvas()
{
    return canvas;
}

Rect Widget::GetRect()
{
    return area;
}

void Widget::EnableOn()
{
    enabled = true;
}

void Widget::EnableOff()
{
    enabled = false;
}

void Widget::VisibleOn()
{
    visible = true;
}

void Widget::VisibleOff()
{
    visible = false;
}

bool Widget::IsEnableOn()
{
    return enabled == true;
}

bool Widget::IsEnableOff()
{
    return enabled == false;
}

bool Widget::IsVisibleOn()
{
    return visible == true;
}

bool Widget::IsVisibleOff()
{
    return visible == false;
}
