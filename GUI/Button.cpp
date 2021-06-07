#include "Button.h"

Button::Button(Canvas * CanvasSource, Rect Size):
    Widget(CanvasSource, Size)
{
}

Button::~Button()
{
}

void Button::Draw()
{
    GetCanvas()->FillRect(GetRect(), Color(34, 177, 76));
}
