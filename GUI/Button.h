#ifndef BUTTON_H
#define BUTTON_H

#include "Widget.h"

class Button: public Widget
{
public:
    Button(Canvas * CanvasSource, Rect Size);
    ~Button();
    void Draw();

private:
};

#endif // BUTTON_H
