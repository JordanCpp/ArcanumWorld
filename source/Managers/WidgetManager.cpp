#include <Arcanum/Managers/WidgetManager.hpp>

using namespace Arcanum::Managers;
using namespace LDL::Graphics;

WidgetManager::WidgetManager(Render* render) :
	_Render(render)
{
}

WidgetManager::~WidgetManager()
{
	for (size_t i = 0; i < _Widgets.size(); i++)
		delete _Widgets[i];
}

Arcanum::Widgets::Button* WidgetManager::Button(const Point2u& pos, const Point2u& size)
{
	auto result = new Arcanum::Widgets::Button(_Render, pos, size);

	_Widgets.push_back(result);

	return result;
}

Arcanum::Widgets::Form* WidgetManager::Form()
{
	auto result = new Arcanum::Widgets::Form(_Render, Point2u(0,0), _Render->Size());

	_Widgets.push_back(result);

	return result;
}