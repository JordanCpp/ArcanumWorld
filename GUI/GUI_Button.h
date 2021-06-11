#ifndef _GUI_Button_h_
#define _GUI_Button_h_

#include "GUI_Widget.h"

namespace GUI
{
	class Button: public Widget
	{
	public:
		Button(Canvas* CanvasSource, Rect Rt);
		void Draw();
	private:
	};
}

#endif