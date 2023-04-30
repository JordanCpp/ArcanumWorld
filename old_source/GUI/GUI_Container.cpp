#include "GUI_Container.h"

using namespace GUI;

Widget* Container::Contains(Point Pt)
{
	for (size_t i = 0; i < widgets.size(); i++)
	{
		if (widgets[i]->GetSize().Contains(Pt))
		{
			return widgets[i];
		}
	}

	return nullptr;
}

void Container::Draw()
{
	for (size_t i = 0; i < widgets.size(); i++)
	{
		widgets[i]->Draw();
	}
}

void Container::Attach(Widget* widget)
{
	widgets.push_back(widget);
}