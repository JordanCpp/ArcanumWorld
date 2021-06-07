#ifndef WIDGET_H
#define WIDGET_H

#include "../Graphics/Rect.h"
#include "../Graphics/Canvas.h"

class Widget
{
public:
    enum
    {
        Normal
    };

    Widget(Canvas * CanvasSource, Rect Size);
    ~Widget();
    virtual void Draw() = 0;
    Canvas * GetCanvas();
    Rect GetRect();
    void EnableOn();
    void EnableOff();
    void VisibleOn();
    void VisibleOff();
    bool IsEnableOn();
    bool IsEnableOff();
    bool IsVisibleOn();
    bool IsVisibleOff();

private:
    Rect area;
    size_t state;
    Canvas * canvas;
    bool enabled;
    bool visible;
};

#endif // WIDGET_H
