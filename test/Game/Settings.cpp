#include <LDL/Core/TestEqual.hpp>
#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Math;

void Default()
{
	Settings settings;

	LDL_TEST_EQUAL(settings.Title()  == "");
	LDL_TEST_EQUAL(settings.Size().x == 0);
	LDL_TEST_EQUAL(settings.Size().y == 0);
	LDL_TEST_EQUAL(settings.Fps()    == 0);
}

void Init()
{
	Settings settings;

	settings.Title("Arcanum title");
	settings.Size(Vec2u(800, 600));
	settings.Fps(60);

	LDL_TEST_EQUAL(settings.Title()  == "Arcanum title");
	LDL_TEST_EQUAL(settings.Size().x == 800);
	LDL_TEST_EQUAL(settings.Size().y == 600);
	LDL_TEST_EQUAL(settings.Fps()    == 60);
}

int main()
{
	Default();
	Init();

	return 0;
}