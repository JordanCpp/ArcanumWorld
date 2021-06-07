#include "Container.h"

Container::Container()
{
}

Container::~Container()
{
}

void Container::Append(Widget * Source)
{
    widgets.push_back(Source);
}

void Container::Draw()
{
    for (size_t i = 0; i < widgets.size(); i++)
    {
        Widget * p = widgets[i];

        if (p->IsEnableOn() && p->IsVisibleOn())
        {
            p->Draw();
        }
    }
}

Widget * Container::Contains(Point pos)
{
    for (size_t i = 0; i < widgets.size(); i++)
    {
        Widget * p = widgets[i];

        if (p->GetRect().Contains(pos))
        {
            return p;
        }
    }

    return nullptr;
}
