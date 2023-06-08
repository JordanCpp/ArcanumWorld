#include <Arcanum/Loaders/SettingsLoader.hpp>

using namespace Arcanum::Loaders;
using namespace LDL::Math;

SettingsLoader::SettingsLoader(Readers::XmlReader* xmlReader) :
	_XmlReader(xmlReader)
{
}

bool SettingsLoader::Reset(const std::string& path, Game::Settings& settings)
{
	bool result = _XmlReader->Reset(path);

	if (result)
	{
		_XmlReader->NextOpening("Config");

		_XmlReader->NextOpening("Video");

		_XmlReader->NextNode("Width");
		size_t width = _XmlReader->ValueInt();

		_XmlReader->NextNode("Heigth");
		size_t heigth = _XmlReader->ValueInt();

		settings.Size(Vec2u(width, heigth));

		_XmlReader->NextNode("Fps");
		settings.Fps(_XmlReader->ValueInt());

		_XmlReader->NextNode("Title");
		settings.Title(_XmlReader->Value());

		_XmlReader->NextClosing("Video");

		_XmlReader->NextClosing("Config");
	}

	return result;
}