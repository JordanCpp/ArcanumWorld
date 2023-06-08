#include <iostream>
#include <Arcanum/Game/Engine.hpp>
#include <Arcanum/Loaders/SettingsLoader.hpp>

using namespace Arcanum::Game;
using namespace Arcanum::Loaders;
using namespace Arcanum::Readers;
using namespace LDL::Math;
using namespace LDL::Core;

int main()
{
	try
	{
		Settings settings;
		XmlReader xmlReader;
		SettingsLoader settingsLoader(&xmlReader);

		settingsLoader.Reset("Config.xml", settings);

		Engine engine(&settings);
		engine.Run();
	}
	catch (const RuntimeError& error)
	{
		std::cout << error.what() << '\n';
	}

	return 0;
}