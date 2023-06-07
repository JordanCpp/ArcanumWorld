#include <iostream>
#include <Arcanum/Game/Engine.hpp>
#include <Arcanum/Game/Settings.hpp>

using namespace Arcanum::Game;
using namespace LDL::Math;
using namespace LDL::Core;

int main()
{
	try
	{
		Settings settings;

		settings.Path("");
		settings.Title("Arcanum World");
		settings.Size(Vec2u(1024, 768));
		settings.Fps(60);

		Engine engine(&settings);
		engine.Run();
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}