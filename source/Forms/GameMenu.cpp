#include <Arcanum/Forms/GameMenu.hpp>

using namespace Arcanum::Forms;
using namespace LDL::Graphics;
using namespace LDL::Math;

GameMenu::GameMenu(LDL::Graphics::Render* render) :
	Widgets::Form(render, Vec2u(0, 0), render->Size()),
	_Button(render, Vec2u(5, 5), Vec2u(130, 35))
{
	Attach(&_Button);
}