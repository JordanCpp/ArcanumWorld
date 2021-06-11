#ifndef _GUI_Window_h_
#define _GUI_Window_h_

#include "GUI_Container.h"

namespace GUI
{
	class Window: public Widget
	{
	public:
		Window(Canvas* CanvasSource, Rect Rt);
		void Attach(Widget* Source);
		Widget* Contains(Point Pt);
		void Draw();
		void Run(Point Pt);
	private:
		Container container;
	};
}
#endif