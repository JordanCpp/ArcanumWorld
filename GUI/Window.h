#ifndef WINDOW_H
#define WINDOW_H

#include "Container.h"

class Window: public Widget
{
public:
    Window(Canvas * CanvasSource, Rect Size);
    ~Window();
    void Draw();
    void Append(Widget * Source);
private:
    Container container;
};

#endif // WINDOW_H
