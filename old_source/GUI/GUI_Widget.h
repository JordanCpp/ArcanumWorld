#ifndef _GUI_Widget_h_
#define _GUI_Widget_h_

#include "../Graphics/Canvas.h"
#include <vector>

namespace GUI
{
	class Widget
	{
	public:
		enum
		{
			Normal,
			Hover,
			Down,
			Up
		};
		Widget(Canvas* CanvasSource, Rect rt);
		void Attach(Widget* widget);
		size_t GetState();
		void State(size_t Value);
		Canvas* GetCanvas();
		Rect GetSize();
		virtual void Draw() = 0;
	private:
		Canvas* canvas;
		Rect area;
		Widget* parent;
		size_t state;
		std::vector<Widget*> widgets;
	};
}

#endif