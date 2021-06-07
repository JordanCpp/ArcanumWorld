#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include "Window.h"

class ImageWindow: public Window
{
public:
    ImageWindow(Canvas * CanvasSource, Rect Size);
    ~ImageWindow();

private:
};

#endif // IMAGEWINDOW_H
