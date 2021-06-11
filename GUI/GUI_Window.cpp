#include "GUI_Window.h"
#include <iostream>

using namespace GUI;

Window::Window(Canvas* CanvasSource, Rect Rt):
	Widget(CanvasSource, Rt)
{
}

void Window::Attach(Widget* Source)
{
	container.Attach(Source);
}

Widget* GUI::Window::Contains(Point Pt)
{
	return container.Contains(Pt);
}

void Window::Draw()
{
	/*
	if (GetState() == Widget::Normal)
	{
		GetCanvas()->FillRect(GetSize(), Color(195, 195, 195));
	}
	else if (GetState() == Widget::Hover)
	{
		GetCanvas()->FillRect(GetSize(), Color(237, 28, 36));
	}
	else if (GetState() == Widget::Down)
	{
		GetCanvas()->FillRect(GetSize(), Color(0, 0, 0));
	}
	else if (GetState() == Widget::Up)
	{
		GetCanvas()->FillRect(GetSize(), Color(0, 0, 0));
	}

	*/

	container.Draw();
}

void Window::Run(Point Pt)
{
	Draw();

	Widget* p = Contains(Pt);

	if (p != nullptr)
	{
		p->State(Widget::Hover);
	}
}