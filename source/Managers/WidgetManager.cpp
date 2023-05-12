#include <Arcanum/Managers/WidgetManager.hpp>

using namespace LDL::Graphics;
using namespace Arcanum::Managers;
using namespace Arcanum::Widgets;

WidgetManager::WidgetManager(Render* render) :
	_Render(render)
{
}

WidgetManager::~WidgetManager()
{
	for (size_t i = 0; i < _Widgets.size(); i++)
		delete _Widgets[i];
}

Button* WidgetManager::GetButton(const Point2u& pos, const Point2u& size)
{
	auto result = new Button(_Render, pos, size);

	_Widgets.push_back(result);

	return result;
}

Form* WidgetManager::GetForm()
{
	auto result = new Form(_Render, Point2u(0,0), _Render->Size());

	_Widgets.push_back(result);

	return result;
}