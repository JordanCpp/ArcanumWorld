#include <Arcanum/Forms/GameMenu.hpp>

using namespace Arcanum::Forms;
using namespace LDL::Graphics;

GameMenu::GameMenu(LDL::Graphics::Render* render) :
	Widgets::Form(render, Point2u(0, 0), render->Size()),
	_Button(render, Point2u(5, 5), Point2u(130, 35))
{
	Attach(&_Button);
}