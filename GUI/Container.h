#ifndef CONTAINER_H
#define CONTAINER_H

#include "Widget.h"
#include <vector>

class Container
{
public:
    Container();
    ~Container();
    void Append(Widget * Source);
    void Draw();
    Widget * Contains(Point pos);

private:
    std::vector<Widget*> widgets;
};

#endif // CONTAINER_H
