#include "Window.h"

Window::Window(Canvas * CanvasSource, Rect Size):
    Widget(CanvasSource, Size)
{
}

Window::~Window()
{
}

void Window::Append(Widget * Source)
{
    container.Append(Source);
}

void Window::Draw()
{
    GetCanvas()->FillRect(GetRect(), Color(255, 0, 0));

    container.Draw();
}
