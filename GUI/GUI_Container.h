#ifndef _GUI_Container_h_
#define _GUI_Container_h_

#include "GUI_Widget.h"

namespace GUI
{
	class Container
	{
	public:
		void Attach(Widget* widget);
		Widget* Contains(Point Pt);
		void Draw();
	private:
		std::vector<Widget*> widgets;
	};
}

#endif