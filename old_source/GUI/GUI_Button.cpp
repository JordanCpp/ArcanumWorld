#include "GUI_Button.h"

using namespace GUI;

Button::Button(Canvas* CanvasSource, Rect Rt) :
	Widget(CanvasSource, Rt)
{
}

void Button::Draw()
{
	if (GetState() == Widget::Normal)
	{
		GetCanvas()->FillRect(GetSize(), Color(237, 28, 36));
	}
	else if (GetState() == Widget::Hover)
	{
		GetCanvas()->FillRect(GetSize(), Color(63, 72, 204));
	}
	else if (GetState() == Widget::Down)
	{
		GetCanvas()->FillRect(GetSize(), Color(0, 0, 0));
	}
	else if (GetState() == Widget::Up)
	{
		GetCanvas()->FillRect(GetSize(), Color(0, 0, 0));
	}
}